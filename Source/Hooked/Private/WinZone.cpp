// Fill out your copyright notice in the Description page of Project Settings.

#include "WinZone.h"

#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "HookedCharacter.h"

// Sets default values
AWinZone::AWinZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	WinZoneCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	WinZoneCollider->SetBoxExtent(FVector(100.f, 100.f, 100.f), true);
	WinZoneCollider->BodyInstance.SetCollisionProfileName("DeathBox");
	WinZoneCollider->GetGenerateOverlapEvents();
	WinZoneCollider->OnComponentBeginOverlap.AddDynamic(this, &AWinZone::WinLevel);

}

// Called when the game starts or when spawned
void AWinZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWinZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


 void AWinZone::WinLevel(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	 AHookedGameMode* GameMode = (AHookedGameMode*)GetWorld()->GetAuthGameMode();
	 GameMode->LevelComplete();
}
