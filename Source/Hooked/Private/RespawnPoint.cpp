// Fill out your copyright notice in the Description page of Project Settings.

#include "RespawnPoint.h"

#include "Components/BoxComponent.h"
#include "HookedCharacter.h"
// Sets default values
ARespawnPoint::ARespawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetSpawnPointTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetSpawnPointTrigger->SetBoxExtent(FVector(100.f, 100.f, 100.f), true);
	SetSpawnPointTrigger->BodyInstance.SetCollisionProfileName("DeathBox");
	SetSpawnPointTrigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);
	SetSpawnPointTrigger->GetGenerateOverlapEvents();
	SetSpawnPointTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARespawnPoint::SetSpawnPoint);

}

// Called when the game starts or when spawned
void ARespawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARespawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARespawnPoint::SetSpawnPoint_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}

