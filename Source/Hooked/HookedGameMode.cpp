// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HookedGameMode.h"
#include "HookedHUD.h"
#include "HookedCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AHookedGameMode::AHookedGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/HookedCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHookedHUD::StaticClass();
}

void AHookedGameMode::BeginPlay() {
	Super::BeginPlay();
}


void AHookedGameMode::CheckLevel() {

}

void AHookedGameMode::EndGame() {

}

void AHookedGameMode::LevelComplete() {

}

void AHookedGameMode::LoadNextLevel() {

}