#include "LifeIsBeautifulPlayerController.h"
#include "LifeIsBeautifulCharacter.h"

void ALifeIsBeautifulPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ALifeIsBeautifulCharacter>(GetPawn());
	if(!PlayerCharacter)
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter is not of type ALifeIsBeautifulCharacter"));
}
