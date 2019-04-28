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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float	frametime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	int32	msec;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool	walking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool	groundPlane;
	// trace_t		groundTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float		impactSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector		previous_origin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector		previous_velocity;
};
