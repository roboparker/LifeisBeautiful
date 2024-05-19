#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "LifeisBeautiful/Time/FGameTimeStruct.h"
#include "LifeIsBeautifulGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinuteChanged, FGameTimeStruct, CurrentTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHourChanged, FGameTimeStruct, CurrentTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDayChanged, FGameTimeStruct, CurrentTime);

UCLASS()
class LIFEISBEAUTIFUL_API ALifeIsBeautifulGameState : public AGameState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time", meta = (AllowPrivateAccess = "true"))
	FGameTimeStruct CurrentTime = FGameTimeStruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time", meta = (AllowPrivateAccess = "true"))
	float TimeDilation = 1.0f;

public:
	ALifeIsBeautifulGameState();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Game Time")
	FOnMinuteChanged OnMinuteChanged;

	UPROPERTY(BlueprintAssignable, Category = "Game Time")
	FOnHourChanged OnHourChanged;

	UPROPERTY(BlueprintAssignable, Category = "Game Time")
	FOnDayChanged OnDayChanged;

};
