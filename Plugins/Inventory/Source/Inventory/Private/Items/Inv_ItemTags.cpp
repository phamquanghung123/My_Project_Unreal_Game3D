// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Inv_ItemTags.h"



namespace GameItems
{
	namespace Equipment
	{
		namespace Weapons
		{
			UE_DEFINE_GAMEPLAY_TAG(Axe, "GameItem.Equipment.Weapons.Axe")
			UE_DEFINE_GAMEPLAY_TAG(Sword, "GameItem.Equipment.Weapons.Sword")
		}
		namespace Cloaks
		{
			UE_DEFINE_GAMEPLAY_TAG(RedCloak, "GameItem.Equipment.Cloaks")
		}
		namespace Masks
		{
			UE_DEFINE_GAMEPLAY_TAG(SteelMask, "GameItem.Equipment.Masks")
		}
	}

	namespace Consumable
	{
		namespace Potions
		{
			namespace Red
			{
				UE_DEFINE_GAMEPLAY_TAG(Small, "GameItem.Consumable.Potions.Red.Small")
				UE_DEFINE_GAMEPLAY_TAG(Large, "GameItem.Consumable.Potions.Red.Large")
			}
			namespace Blue
			{
				UE_DEFINE_GAMEPLAY_TAG(Small, "GameItem.Consumable.Potions.Blue.Small")
				UE_DEFINE_GAMEPLAY_TAG(Large, "GameItem.Consumable.Potions.Blue.Large")
			}
		}
	}

	namespace Craftables
	{
		UE_DEFINE_GAMEPLAY_TAG(FireFernFruit, "GameItem.Craftable.FireFernFruit")
		UE_DEFINE_GAMEPLAY_TAG(LuminDaisy, "GameItem.Craftable.LuminDaisy")
		UE_DEFINE_GAMEPLAY_TAG(ScorchPetalBlossom, "GameItem.Craftable.ScorchPetalBlossom")
	}
}

