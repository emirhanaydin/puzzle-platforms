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

	if (FVector::Distance(Location, StartPoint) > TargetDistance) {
		FVector tmp = StartPoint;
		StartPoint = EndPoint;
		EndPoint = tmp;

		Direction *= -1;
	}

	Location += Direction * Speed * DeltaSeconds;
	SetActorLocation(Location);
}

void AMovingPlatform::BeginPlay()
{
	if (!HasAuthority()) return;

	Super::BeginPlay();

	StartPoint = GetActorLocation();
	EndPoint = GetTransform().TransformPosition(TargetLocation);
	Direction = (EndPoint - StartPoint).GetSafeNormal();
	TargetDistance = FVector::Distance(StartPoint, EndPoint);

	SetReplicates(true);
	SetReplicateMovement(true);
}
