#include "GameSaveData.h"

#include "Kismet/GameplayStatics.h"

UGameSaveData::UGameSaveData()
{
	SlotName = TEXT("SaveSlot0");
	UserIndex = 0;
}

void UGameSaveData::SaveGame() const
{
	UGameSaveData* SaveGameInstance = Cast<UGameSaveData>(UGameplayStatics::CreateSaveGameObject(UGameSaveData::StaticClass()));
	SaveGameInstance->SlotName = "GameSaveData";
	SaveGameInstance->UserIndex = 0;

	FAsyncSaveGameToSlotDelegate SavedDelegate;
	SavedDelegate.BindLambda([this](const FString& SlotName, const int32 UserIndex, bool bSuccess)
	{
		if (bSuccess)
		{
			UE_LOG(LogTemp, Log, TEXT("Game saved successfully"));
			OnSaveGameComplete.Broadcast();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to save game"));
		}
	});

	UGameplayStatics::AsyncSaveGameToSlot (SaveGameInstance, SaveGameInstance->SlotName, SaveGameInstance->UserIndex, SavedDelegate);
}

void UGameSaveData::LoadGame() const
{
	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindLambda([this](const FString&, const int32, USaveGame* LoadedGameData)
	{
		if (LoadedGameData)
		{
			UE_LOG(LogTemp, Log, TEXT("Game loaded successfully"));
			OnLoadGameComplete.Broadcast(LoadedGameData);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load game"));
		}
	});

	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, UserIndex, LoadedDelegate);
}

void UGameSaveData::DeleteGame() const
{
	if (UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		UGameplayStatics::DeleteGameInSlot(SlotName, UserIndex);
		UE_LOG(LogTemp, Log, TEXT("Game save data deleted successfully"));
		OnSaveGameDeleted.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No save data found to delete"));
	}
}
