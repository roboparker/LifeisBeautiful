#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonActivatableWidget.h"
#include "PlayerHUD.generated.h"

UCLASS()
class LIFEISBEAUTIFUL_API UPlayerHUD : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Widgets")
	void PushWidget(TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Widgets")
	void PopWidget();
};
