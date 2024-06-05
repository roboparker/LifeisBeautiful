#include "LifeIsBeautifulGameInstance.h"

#include "Kismet/GameplayStatics.h"
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



void ULifeIsBeautifulGameInstance::SaveGame() const
{
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

	UGameplayStatics::AsyncSaveGameToSlot (GameSaveData, GameSaveData->GetSlotName(), GameSaveData->GetUserIndex(), SavedDelegate);
}

void ULifeIsBeautifulGameInstance::LoadGame() const
{
	if(!UGameplayStatics::DoesSaveGameExist(GameSaveData->GetSlotName(), GameSaveData->GetUserIndex()))
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
		OnLoadGameComplete.Broadcast(Cast<UGameSaveData>(LoadedGameData));
	});

	UGameplayStatics::AsyncLoadGameFromSlot(GameSaveData->GetSlotName(), GameSaveData->GetUserIndex(), LoadedDelegate);
}

void ULifeIsBeautifulGameInstance::DeleteGame() const
{
	if (!UGameplayStatics::DoesSaveGameExist(GameSaveData->GetSlotName(), GameSaveData->GetUserIndex()))
	{
		FFrame::KismetExecutionMessage(TEXT("No save data found to delete"), ELogVerbosity::Error);
		UE_LOG(LogTemp, Error, TEXT("No save data found to delete"));

		return;
	}

	UGameplayStatics::DeleteGameInSlot(GameSaveData->GetSlotName(), GameSaveData->GetUserIndex());
	UE_LOG(LogTemp, Log, TEXT("Game save data deleted successfully"));
	OnSaveGameDeleted.Broadcast();
}