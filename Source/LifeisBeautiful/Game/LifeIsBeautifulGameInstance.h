#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LifeIsBeautifulGameInstance.generated.h"

class UGameSaveData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveGameComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadGameComplete, UGameSaveData*, LoadedGameData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveGameDeleted);

UCLASS()
class LIFEISBEAUTIFUL_API ULifeIsBeautifulGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, category = "Save Data", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameSaveData> GameSaveDataClass;

	UPROPERTY(BlueprintReadOnly,category = "Save Data", meta = (AllowPrivateAccess = "true"))
	UGameSaveData* GameSaveData;

public:
	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnSaveGameComplete OnSaveGameComplete;

	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnLoadGameComplete OnLoadGameComplete;

	UPROPERTY(BlueprintAssignable, Category = "Save Data")
	FOnSaveGameDeleted OnSaveGameDeleted;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void SaveGame() const;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void LoadGame();

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void DeleteGame() const;
};
