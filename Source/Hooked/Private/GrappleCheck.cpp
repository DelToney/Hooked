// Fill out your copyright notice in the Description page of Project Settings.

#include "GrappleCheck.h"


// Sets default values for this component's properties
UGrappleCheck::UGrappleCheck()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	grapplable = true;
}


// Called when the game starts
void UGrappleCheck::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrappleCheck::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

