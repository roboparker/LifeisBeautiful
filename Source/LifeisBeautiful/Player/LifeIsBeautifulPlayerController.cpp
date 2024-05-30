#include "LifeIsBeautifulPlayerController.h"
#include "LifeIsBeautifulCharacter.h"
#include "LifeisBeautiful/Game/LifeisBeautifulGameMode.h"

void ALifeIsBeautifulPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ALifeIsBeautifulCharacter>(GetPawn());
	if(!PlayerCharacter)
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter is not of type ALifeIsBeautifulCharacter"));

	LifeIsBeautifulGameMode = Cast<ALifeIsBeautifulGameMode>(GetWorld()->GetAuthGameMode());
	if(!LifeIsBeautifulGameMode)
		UE_LOG(LogTemp, Error, TEXT("GameMode is not of type ALifeIsBeautifulGameMode"));

	LifeIsBeautifulGameMode->OnGamePaused.AddDynamic(this, &ALifeIsBeautifulPlayerController::OnGamePaused);
	LifeIsBeautifulGameMode->OnGameResumed.AddDynamic(this, &ALifeIsBeautifulPlayerController::OnGameResumed);
}

void ALifeIsBeautifulPlayerController::OnGamePaused()
{
	bShowMouseCursor = true;

	const FInputModeGameAndUI InputMode;
	SetInputMode(InputMode);
}

void ALifeIsBeautifulPlayerController::OnGameResumed()
{
	bShowMouseCursor = false;

	const FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
