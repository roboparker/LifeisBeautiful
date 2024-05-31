﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSaveData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveGameComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadGameComplete, USaveGame*, LoadedGameData);

UCLASS(Blueprintable)
class LIFEISBEAUTIFUL_API UGameSaveData : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Save Data", meta = (AllowPrivateAccess="true"))
	FString SlotName;

	UPROPERTY(BlueprintReadWrite, Category = "Save Data", meta = (AllowPrivateAccess="true"))
	int32 UserIndex;

public:
	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnSaveGameComplete OnSaveGameComplete;

	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnLoadGameComplete OnLoadGameComplete;

	UGameSaveData();
	
	UFUNCTION(BlueprintCallable, Category = "Game")
	void SaveGame() const;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void LoadGame() const;
};