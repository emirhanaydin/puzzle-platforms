// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!HasAuthority()) return;

	FVector Location = GetActorLocation();
	Location.X += DeltaSeconds * Speed;
	SetActorLocation(Location);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority()) return;

	SetReplicates(true);
	SetReplicateMovement(true);
}
