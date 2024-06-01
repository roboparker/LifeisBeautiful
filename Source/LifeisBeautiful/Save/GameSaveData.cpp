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
		if (!bSuccess)
		{
			FFrame::KismetExecutionMessage(TEXT("Failed to save game"), ELogVerbosity::Error);
			UE_LOG(LogTemp, Error, TEXT("Failed to save game"));

			return;
		}

		UE_LOG(LogTemp, Log, TEXT("Game saved successfully"));
		OnSaveGameComplete.Broadcast();
	});

	UGameplayStatics::AsyncSaveGameToSlot (SaveGameInstance, SaveGameInstance->SlotName, SaveGameInstance->UserIndex, SavedDelegate);
}

void UGameSaveData::LoadGame() const
{
	if(!UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		FFrame::KismetExecutionMessage(TEXT("No save data found to load"), ELogVerbosity::Warning);
		UE_LOG(LogTemp, Warning, TEXT("No save data found to load"));

		return;
	}

	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindLambda([this](const FString&, const int32, USaveGame* LoadedGameData)
	{
		if (!LoadedGameData)
		{
			FFrame::KismetExecutionMessage(TEXT("Failed to load game"), ELogVerbosity::Error);
			UE_LOG(LogTemp, Error, TEXT("Failed to load game"));

			return;
		}

		UE_LOG(LogTemp, Log, TEXT("Game loaded successfully"));
		OnLoadGameComplete.Broadcast(LoadedGameData);
	});

	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, UserIndex, LoadedDelegate);
}

void UGameSaveData::DeleteGame() const
{
	if (!UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		FFrame::KismetExecutionMessage(TEXT("No save data found to delete"), ELogVerbosity::Error);
		UE_LOG(LogTemp, Error, TEXT("No save data found to delete"));

		return;
	}

	UGameplayStatics::DeleteGameInSlot(SlotName, UserIndex);
	UE_LOG(LogTemp, Log, TEXT("Game save data deleted successfully"));
	OnSaveGameDeleted.Broadcast();
}
