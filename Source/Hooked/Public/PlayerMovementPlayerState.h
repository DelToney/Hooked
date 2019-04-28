// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerMovementPlayerState.generated.h"

#define	MAX_PS_EVENTS			2

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerMovementPlayerState {


	GENERATED_USTRUCT_BODY()
	
	FPlayerMovementPlayerState(){};


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			pm_type;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			bobCycle;		// for view bobbing and footstep generation
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			pm_flags;		// ducked, jump_held, etc
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			pm_time;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector		origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector		velocity;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			weaponTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			gravity;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			groundEntityNum;// ENTITYNUM_NONE = in air




	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector		grapplePoint;	// location of grapple to pull towards if PMF_GRAPPLE_PULL
	




	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			eFlags;			// copied to entityState_t->eFlags

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			eventSequence;	// pmove generated events
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			events[MAX_PS_EVENTS];
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			eventParms[MAX_PS_EVENTS];
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			externalEvent;	// events set on player from another source
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			externalEventParm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			externalEventTime;




	// not communicated over the net at all
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			pmove_framecount;	// FIXME: don't transmit over the network
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	int			entityEventSequence;
	
	
};
