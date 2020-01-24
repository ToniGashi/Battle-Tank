// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackMeshComponent.h"

void UTankTrackMeshComponent::SetThrottle(float throttle)
{
	FVector ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	if (!GetOwner()->GetRootComponent()) return;
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (TankRoot== nullptr) return;
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}