#include "TimeBasedDirectionalLight.h"

#include "Components/DirectionalLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../LifeisBeautifulGameState.h"

ATimeBasedDirectionalLight::ATimeBasedDirectionalLight()
{
	PrimaryActorTick.bCanEverTick = false;
	DirectionalLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("DirectionalLight"));
	RootComponent = DirectionalLight;
}

void ATimeBasedDirectionalLight::BeginPlay()
{
	Super::BeginPlay();

	if (ALifeIsBeautifulGameState* GameState = Cast<ALifeIsBeautifulGameState>(UGameplayStatics::GetGameState(GetWorld())))
	{
		GameState->OnMinuteChanged.AddDynamic(this, &ATimeBasedDirectionalLight::OnMinuteChanged);
	}
	
}

void ATimeBasedDirectionalLight::OnMinuteChanged(FGameTimeStruct CurrentTime)
{
	DirectionalLight->AddLocalRotation(FRotator(360.0f / 1440.0f, 0, 0));
}