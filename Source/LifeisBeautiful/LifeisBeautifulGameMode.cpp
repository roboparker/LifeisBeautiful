// Copyright Epic Games, Inc. All Rights Reserved.

#include "LifeisBeautifulGameMode.h"
#include "LifeisBeautifulCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALifeisBeautifulGameMode::ALifeisBeautifulGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
