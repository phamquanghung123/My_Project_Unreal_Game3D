// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Inv_HightlightableStaticMesh.h"

void UInv_HightlightableStaticMesh::Highlight_Implementation()
{
	SetOverlayMaterial(HighlightMaterial);
}

void UInv_HightlightableStaticMesh::UnHighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
