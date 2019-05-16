// Fill out your copyright notice in the Description page of Project Settings.

#include "KillBox.h"

#include "HookedProjectile.h"
#include "Components/BoxComponent.h"
#include "HookedCharacter.h"


// Sets default values
AKillBox::AKillBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	KillZone = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	KillZone->SetBoxExtent(FVector(100.f, 100.f, 100.f), true);
	KillZone->BodyInstance.SetCollisionProfileName("DeathBox");
	KillZone->GetGenerateOverlapEvents();
	KillZone->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);
	KillZone->OnComponentBeginOverlap.AddDynamic(this, &AKillBox::KillPlayer);// << looking for infop on delegates here
}

// Called when the game starts or when spawned
void AKillBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillBox::KillPlayer(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	for (TActorIterator<AHookedCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr) {
		
		PlayerObject = *ActorItr;
	}

	UE_LOG(LogTemp, Display, TEXT("target hit %f, %f, %f"), 
						this->GetTransform().GetLocation().X, 
						this->GetTransform().GetLocation().Y, 
						this->GetTransform().GetLocation().Z);


	if (OtherActor == (AActor*)PlayerObject) {
		PlayerObject->OnDeath();
	}

}

