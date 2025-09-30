// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagement/Utils/Inv_InventoryStatics.h"
#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "DataType/Inv_GridTypes.h"
#include "Items/Components/Inv_ItemComponent.h"
#include "Widgets/Inventory/InventoryBase/Inv_InventoryBase.h"

UInv_InventoryComponent* UInv_InventoryStatics::GetInventoryComponent(const APlayerController* PlayerController)
{
	if(!IsValid(PlayerController)) return nullptr;
	UInv_InventoryComponent* InventoryComponent = PlayerController->FindComponentByClass<UInv_InventoryComponent>();
	return InventoryComponent;

}

EInv_ItemCategory UInv_InventoryStatics::GetItemCategoryFromItemComp(UInv_ItemComponent* ItemComp)
{
	if (!IsValid(ItemComp)) return EInv_ItemCategory::Node;
	return ItemComp->GetItemManifest().GetItemCategory();
}

void UInv_InventoryStatics::ItemHovered(APlayerController* PC, UInv_InventoryItem* Item)
{
	UInv_InventoryComponent* IC = GetInventoryComponent(PC);
	if (!IsValid(IC)) return;

	UInv_InventoryBase* InventoryBase = IC->GetInventoryMenu();
	if (!IsValid(InventoryBase)) return;

	if (InventoryBase->HasHoverItem()) return;

	InventoryBase->OnItemHovered(Item);
}

void UInv_InventoryStatics::ItemUnhovered(APlayerController* PC)
{
	UInv_InventoryComponent* IC = GetInventoryComponent(PC);
	if (!IsValid(IC)) return;

	UInv_InventoryBase* InventoryBase = IC->GetInventoryMenu();
	if (!IsValid(InventoryBase)) return;

	InventoryBase->OnItemUnHovered();
}

UInv_HoverItem* UInv_InventoryStatics::GetHoverItem(APlayerController* PC)
{
	UInv_InventoryComponent* IC = GetInventoryComponent(PC);
	if (!IsValid(IC)) return nullptr;

	UInv_InventoryBase* InventoryBase = IC->GetInventoryMenu();
	if (!IsValid(InventoryBase)) return nullptr;

	return InventoryBase->GetHoverItem();
}

UInv_InventoryBase* UInv_InventoryStatics::GetInventoryWidget(APlayerController* PC)
{
	UInv_InventoryComponent* IC = GetInventoryComponent(PC);
	if (!IsValid(IC)) return nullptr;

	return IC->GetInventoryMenu();
}