// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category = "Radius")
		float AcceptanceRadius = 8000; //how close can AI Tank get.
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override; 
};
