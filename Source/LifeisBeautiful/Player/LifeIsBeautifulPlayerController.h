#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LifeIsBeautifulPlayerController.generated.h"

class ALifeIsBeautifulCharacter;

UCLASS()
class LIFEISBEAUTIFUL_API ALifeIsBeautifulPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Controller", meta = (AllowPrivateAccess = "true"))
	ALifeIsBeautifulCharacter* PlayerCharacter;

protected:
	virtual void BeginPlay();

public:
	ALifeIsBeautifulCharacter* GetPlayerCharacter() const { return PlayerCharacter; }
};
