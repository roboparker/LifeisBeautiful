#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LifeIsBeautifulGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGamePaused);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameResumed);

UCLASS(minimalapi)
class ALifeIsBeautifulGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnGamePaused OnGamePaused;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnGameResumed OnGameResumed;

	ALifeIsBeautifulGameMode();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void PauseGame() const;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ResumeGame() const;
};



