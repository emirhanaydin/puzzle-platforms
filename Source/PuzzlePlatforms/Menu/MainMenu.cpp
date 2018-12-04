// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Widget.h"

bool UMainMenu::Initialize() {
	if (!Super::Initialize()) return false;

	if (!ensure(ButtonMainHost != nullptr)) return false;
	ButtonMainHost->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonMainHost);

	if (!ensure(ButtonMainJoin != nullptr)) return false;
	ButtonMainJoin->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonMainJoin);

	if (!ensure(ButtonJoinBack != nullptr)) return false;
	ButtonJoinBack->OnClicked.AddDynamic(this, &UMainMenu::OnClickedButtonJoinBack);

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

void UMainMenu::OnClickedButtonMainHost() {
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}

void UMainMenu::OnClickedButtonMainJoin() {
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(WidgetJoinMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(WidgetJoinMenu);
}

void UMainMenu::OnClickedButtonJoinBack() {
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(WidgetMainMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(WidgetMainMenu);
}

void UMainMenu::SetMenuInterface(IMenuInterface *MenuInterface) {
	this->MenuInterface = MenuInterface;
}