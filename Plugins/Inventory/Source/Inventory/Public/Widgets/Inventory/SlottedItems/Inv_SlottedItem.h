// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Items/Inv_InventoryItem.h"
#include "Inv_SlottedItem.generated.h"

class UTextBlock;
/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSlottedItemClicked, int32, GridIndex, const FPointerEvent&, MouseEvent);

UCLASS()
class INVENTORY_API UInv_SlottedItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

	void SetIsStackable(bool bStackable) { bIsStackable = bStackable; }
	bool GetIsStackable() const { return bIsStackable; }

	UImage* GetImageIcon() const { return Image_Icon; }
	void SetImageBrush(const FSlateBrush& Brush) const;

	void SetGridIndex(int32 Index) { GridIndex = Index; }
	int32 GetGridIndex()const { return GridIndex; }

	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	FIntPoint GetGridDimensions()const { return GridDimensions; }

	UInv_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	void SetInventoryItem(UInv_InventoryItem* Item) { InventoryItem = Item; }

	void UpdateStackCount(int32 StackCount);

	FSlottedItemClicked OnSlottedItemClicked;


private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;

	int32 GridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	bool bIsStackable{ false };

};
