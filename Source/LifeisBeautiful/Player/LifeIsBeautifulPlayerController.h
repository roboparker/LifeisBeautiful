#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LifeIsBeautifulPlayerController.generated.h"

class ALifeIsBeautifulGameMode;
class ALifeIsBeautifulCharacter;

UCLASS()
class LIFEISBEAUTIFUL_API ALifeIsBeautifulPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Controller", meta = (AllowPrivateAccess = "true"))
	ALifeIsBeautifulCharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Controller", meta = (AllowPrivateAccess = "true"))
	ALifeIsBeautifulGameMode* LifeIsBeautifulGameMode;

protected:
	virtual void BeginPlay();

	UFUNCTION()
	void OnGamePaused();

	UFUNCTION()
	void OnGameResumed();

public:
	ALifeIsBeautifulCharacter* GetPlayerCharacter() const { return PlayerCharacter; }
};
