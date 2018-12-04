// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"

bool UMainMenu::Initialize() {
	if (!Super::Initialize()) return false;

	if (!ensure(ButtonHost != nullptr)) return false;
	ButtonHost->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonHost);

	if (!ensure(ButtonJoin != nullptr)) return false;
	ButtonJoin->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonJoin);

	this->AddToViewport();

	UWorld *World = GetWorld();
	if (!ensure(World != nullptr)) return false;

	APlayerController *PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return false;

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(this->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;

	return true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel *Inlevel, UWorld *InWorld) {
	Super::OnLevelRemovedFromWorld(Inlevel, InWorld);

	if (!ensure(InWorld != nullptr)) return;

	APlayerController *PlayerController = InWorld->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputMode;

	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::OnClickedButtonHost() {
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}

void UMainMenu::OnClickedButtonJoin() {
	UE_LOG(LogTemp, Display, TEXT("OnClicked: ButtonJoin"));
}

void UMainMenu::SetMenuInterface(IMenuInterface *MenuInterface) {
	this->MenuInterface = MenuInterface;
}