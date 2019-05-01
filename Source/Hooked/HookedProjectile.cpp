// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HookedProjectile.h"
#include "Public/GrappleCheck.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SphereComponent.h"

AHookedProjectile::AHookedProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AHookedProjectile::OnHit);		// set up a notification for when this component hits something blocking

	

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	//Mesh Setup
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	BulletMesh->SetupAttachment(RootComponent);
	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 7000.f;
	ProjectileMovement->MaxSpeed = 10000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	// Die after 3 seconds by default
	InitialLifeSpan = 30.0f;

	
	
}

void AHookedProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// get player object reference
	for (TActorIterator<AHookedCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr) {
		
		PlayerObject = *ActorItr;
	}
	
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
				UE_LOG(LogTemp, Display, TEXT("COLLIDED"));
		//get Grapple Check component
		UGrappleCheck* GrappleCheck = Cast<UGrappleCheck>(OtherActor->GetComponentByClass(UGrappleCheck::StaticClass()));
		if (GrappleCheck != NULL){
			if (GrappleCheck->grapplable) {

				// PlayerObject->Grapple(this);
			}
		}
		ProjectileMovement->Velocity = FVector::ZeroVector;
	}
}