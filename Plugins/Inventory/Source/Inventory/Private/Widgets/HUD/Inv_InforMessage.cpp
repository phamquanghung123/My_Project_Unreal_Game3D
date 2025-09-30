// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/Inv_InforMessage.h"
#include "Components/TextBlock.h"


void UInv_InforMessage::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Text_Message->SetText(FText::GetEmpty());
	MessageHide();
}

void UInv_InforMessage::SetMessage(const FText& Message)
{
	Text_Message->SetText(Message);
	if (!bIsMessageActive)
	{
		MessageShow();
	}
	bIsMessageActive = true;

	GetWorld()->GetTimerManager().SetTimer(MessageTimer, [this]()
		{
			MessageHide();
			bIsMessageActive = false;
		}, MessageLifeTime, false);
}