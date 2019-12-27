// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
};
