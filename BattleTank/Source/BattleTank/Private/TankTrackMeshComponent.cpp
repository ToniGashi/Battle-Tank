// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackMeshComponent.h"

void UTankTrackMeshComponent::SetThrottle(float throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, throttle);
}