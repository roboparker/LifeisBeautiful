#include "LifeIsBeautifulHUD.h"

#include "PlayerHUD.h"

void ALifeIsBeautifulHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!CommonUserWidgetClass)
	{
		return;
	}

	CommonUserWidget = CreateWidget<UPlayerHUD>(GetWorld(), CommonUserWidgetClass);

	if (!CommonUserWidget)
	{
		return;
	}

	CommonUserWidget->AddToViewport();
}
