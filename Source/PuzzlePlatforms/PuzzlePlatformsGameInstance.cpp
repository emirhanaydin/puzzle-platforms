// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"


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
}

void UPuzzlePlatformsGameInstance::Join(const FString IPAddress)
{
	if (!ensure(GEngine != nullptr)) return;

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Cyan, FString::Printf(TEXT("Connected: %s"), *IPAddress), true, FVector2D(3, 3));
}
