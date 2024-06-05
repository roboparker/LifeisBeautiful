#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LifeIsBeautifulGameInstance.generated.h"

class UGameSaveData;

UCLASS()
class LIFEISBEAUTIFUL_API ULifeIsBeautifulGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, category = "Save Data", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameSaveData> GameSaveDataClass;

	UPROPERTY(BlueprintReadOnly,category = "Save Data", meta = (AllowPrivateAccess = "true"))
	UGameSaveData* GameSaveData;

public:
	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void SaveGame() const;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void LoadGame() const;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void DeleteGame() const;
};
