#include "LifeIsBeautifulGameInstance.h"

#include "LifeisBeautiful/Save/GameSaveData.h"

void ULifeIsBeautifulGameInstance::Init()
{
	Super::Init();

	if(!GameSaveDataClass)
	{
		UE_LOG(LogTemp, Error, TEXT("GameSaveDataClass is nullptr"));

		return;
	}
	
	GameSaveData = NewObject<UGameSaveData>(this, GameSaveDataClass);
	
	if (!GameSaveData)
		UE_LOG(LogTemp, Error, TEXT("Failed to create GameSaveData"));
}
