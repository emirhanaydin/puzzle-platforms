// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer &ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformsGameInstance: Constructor"))
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("UPuzzlePlatformsGameInstance: Init"))
}

void UPuzzlePlatformsGameInstance::Host()
{
	if (!ensure(GEngine != nullptr)) return;

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Cyan, TEXT("Host"), true, FVector2D(3, 3));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen?spectatoronly=true -server");
}

void UPuzzlePlatformsGameInstance::Join(const FString IPAddress)
{
	if (!ensure(GEngine != nullptr)) return;

	APlayerController *PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Cyan, FString::Printf(TEXT("Connected: %s"), *IPAddress), true, FVector2D(3, 3));
}