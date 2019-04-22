// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPlayerMovementManager.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerMovementManager {

	GENERATED_USTRUCT_BODY()

	FPlayerMovementManager(){};

	FVector		forward, right, up;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float	frametime;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32	msec;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool	walking;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool	groundPlane;
	// trace_t		groundTrace;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float		impactSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector		previous_origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector		previous_velocity;
};
