#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LifeisBeautiful/Time/FGameTimeStruct.h"
#include "GameSaveData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveGameComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadGameComplete, USaveGame*, LoadedGameData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveGameDeleted);

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
	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnSaveGameComplete OnSaveGameComplete;

	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnLoadGameComplete OnLoadGameComplete;

	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnSaveGameDeleted OnSaveGameDeleted;

	FString GetSlotName() const { return SlotName; }

	int32 GetUserIndex() const { return UserIndex; }
};
