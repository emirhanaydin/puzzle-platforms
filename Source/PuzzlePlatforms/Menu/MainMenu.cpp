// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"

bool UMainMenu::Initialize() {
	if (!Super::Initialize()) return false;

	if (!ensure(ButtonHost != nullptr)) return false;
	ButtonHost->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonHost);

	if (!ensure(ButtonJoin != nullptr)) return false;
	ButtonJoin->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonJoin);

	return true;
}

void UMainMenu::OnClickedButtonHost() {
	UE_LOG(LogTemp, Display, TEXT("OnClicked: ButtonHost"));
}

void UMainMenu::OnClickedButtonJoin() {
	UE_LOG(LogTemp, Display, TEXT("OnClicked: ButtonJoin"))
}