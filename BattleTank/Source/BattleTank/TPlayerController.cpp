// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TPlayerController.h"

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* t1 = GetControlledTank();
	if (!t1)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("this is %s"), *(t1->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Here."));
}
ATank* ATPlayerController::GetControlledTank() const
{
	return (Cast<ATank>(GetPawn()));
}
