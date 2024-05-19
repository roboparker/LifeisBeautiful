#include "LifeisBeautifulGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ALifeIsBeautifulGameMode::ALifeIsBeautifulGameMode()
{
}


void ALifeIsBeautifulGameMode::PauseGame() const
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	OnGamePaused.Broadcast();
}

void ALifeIsBeautifulGameMode::ResumeGame() const
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	OnGameResumed.Broadcast();
}
