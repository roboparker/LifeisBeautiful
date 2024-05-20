#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LifeIsBeautifulHUD.generated.h"

class UCommonActivatableWidget;
class UPlayerHUD;

UCLASS()
class LIFEISBEAUTIFUL_API ALifeIsBeautifulHUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UPlayerHUD> CommonUserWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
	UPlayerHUD* CommonUserWidget;
	
	void BeginPlay();
};
