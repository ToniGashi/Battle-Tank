// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0, RawNewElevation, 0));

	//UE_LOG(LogTemp,Warning,TEXT("Rotating at a speed of: %f"),RelativeSpeed);
}