// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPlayerMovementManager.h"
#include "WIP_PM.generated.h"



/**
 * 
 */
UCLASS()
class HOOKED_API AWIP_PM : public APlayerController
{
	GENERATED_BODY()

	#define JUMP_VELOCITY 600;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Manager")
	FPlayerMovementManager pmm;
	

	float pm_stopspeed;
	float pm_accelerate;
	float pm_airaccelerate;
	float pm_flyaccelerate;
	float pm_friction;
	
};

