// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillBox.generated.h"

UCLASS()
class HOOKED_API AKillBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillBox();

	UPROPERTY(BlueprintReadWrite)
	class UBoxComponent* KillZone;

	//Delegate function to "On Component Begin Overlap"
	UFUNCTION(BlueprintCallable)
	void KillPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AHookedCharacter* PlayerObject;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
