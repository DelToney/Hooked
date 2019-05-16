// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "HookedCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HookedGameMode.generated.h"

UCLASS(minimalapi)
class AHookedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHookedGameMode();

	void EndGame();
	void LevelComplete();
	void LoadNextLevel();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultLevelCompleteWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	UUserWidget* LevelCompleteWidget;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultGameCompleteWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	UUserWidget* GameCompleteWidget;

	private:

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess  = "true"), Category = "Levels")
	TArray<FString> Levels;

	AHookedCharacter* Controller;

	int32 currentLevelIndex;
	FString NextLevel;

	void CheckLevel();
};



