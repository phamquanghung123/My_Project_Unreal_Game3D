// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Inv_FastArray.generated.h"

class UInv_InventoryItem;
class UInv_ItemComponent;
class UInv_InventoryComponent;
struct FGameplayTag;


USTRUCT(BlueprintType)
struct FInv_InventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	FInv_InventoryEntry(){}

private:
	friend struct FInv_InventoryFastArray;
	friend UInv_InventoryComponent;

	UPROPERTY()
	TObjectPtr<UInv_InventoryItem> Item = nullptr;
};



USTRUCT(BlueprintType)
struct FInv_InventoryFastArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:

	FInv_InventoryFastArray() :OwnerComponent(nullptr){}
	FInv_InventoryFastArray(UActorComponent* InOwnerComponent ) : OwnerComponent(InOwnerComponent) {}

	TArray<UInv_InventoryItem*> GetAllItems() const;

	//FFastArraySerialization contract
	void PreReplicatedRemove(const TArrayView<int32> RemoveIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddIndices, int32 FinalSize);
	//End FFastArraySerialization contract

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
	{
		return FastArrayDeltaSerialize<FInv_InventoryEntry, FInv_InventoryFastArray>(Entries, DeltaParams, *this);
	}

	UInv_InventoryItem* AddEntry(UInv_ItemComponent* ItemComponent);
	UInv_InventoryItem* AddEntry(UInv_InventoryItem* Item);
	void RemoveEntry(UInv_InventoryItem* Item);
	UInv_InventoryItem* FindFirstItemByType(const FGameplayTag& ItemType);


private:
	friend UInv_InventoryComponent;

	UPROPERTY()
	TArray<FInv_InventoryEntry> Entries;
	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;

};


template<>
struct TStructOpsTypeTraits<FInv_InventoryFastArray> : public TStructOpsTypeTraitsBase2<FInv_InventoryFastArray>
{
	enum {WithNetDeltaSerializer = true};
};