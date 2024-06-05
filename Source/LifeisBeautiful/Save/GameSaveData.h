#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LifeisBeautiful/Time/FGameTimeStruct.h"
#include "GameSaveData.generated.h"

UCLASS(Blueprintable)
class LIFEISBEAUTIFUL_API UGameSaveData : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Save Data", meta = (AllowPrivateAccess="true"))
	FGameTimeStruct GameTime;

	UPROPERTY(BlueprintReadWrite, Category = "Save Data", meta = (AllowPrivateAccess="true"))
	FString SlotName = "Slot0";

	UPROPERTY(BlueprintReadWrite, Category = "Save Data", meta = (AllowPrivateAccess="true"))
	int32 UserIndex = 0;

public:
	FString GetSlotName() const { return SlotName; }

	int32 GetUserIndex() const { return UserIndex; }
};
