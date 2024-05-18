#include "LifeIsBeautifulGameState.h"

ALifeIsBeautifulGameState::ALifeIsBeautifulGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALifeIsBeautifulGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FGameTimeStruct OldTime = CurrentTime;

	CurrentTime.AddSeconds(DeltaTime * TimeDilation);

	if (CurrentTime.Minute != OldTime.Minute)
	{
		OnMinuteChanged.Broadcast(CurrentTime);
	}

	if (CurrentTime.Hour != OldTime.Hour)
	{
		OnHourChanged.Broadcast(CurrentTime);
	}

	if (CurrentTime.Day != OldTime.Day)
	{
		OnDayChanged.Broadcast(CurrentTime);
	}
}
