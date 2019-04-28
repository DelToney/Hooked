// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPlayerMovementManager.h"
#include "PlayerMovementPlayerState.h"
#include "WIP_PM.generated.h"


#define	MIN_WALK_NORMAL	0.7f		// can't walk on very steep slopes

#define	STEPSIZE		18

#define	TIMER_LAND		130
#define	TIMER_GESTURE	(34*66+50)

#define	OVERCLIP		1.001f


/**
 * 
 */
UCLASS()
class HOOKED_API AWIP_PM : public APlayerController
{
	GENERATED_BODY()

	#define JUMP_VELOCITY 600;

public:

	AWIP_PM(){};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FPlayerMovementManager pmm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	FPlayerMovementPlayerState pm_playerstate;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	float pm_stopspeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	float pm_accelerate;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	float pm_airaccelerate;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	float pm_flyaccelerate;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	float pm_friction;

	// void PM_ClipVelocity( FVector in, FVector normal, FVector out, float overbounce );
	// void PM_AddTouchEnt( int32 entityNum );
	// void PM_AddEvent( int32 newEvent );
	
};

