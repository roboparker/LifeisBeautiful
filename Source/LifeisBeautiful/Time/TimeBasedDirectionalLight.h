#pragma once

#include "CoreMinimal.h"
#include "FGameTimeStruct.h"
#include "GameFramework/Actor.h"
#include "TimeBasedDirectionalLight.generated.h"

UCLASS()
class LIFEISBEAUTIFUL_API ATimeBasedDirectionalLight : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light", meta = (AllowPrivateAccess = "true"))
	UDirectionalLightComponent* DirectionalLight;

	UFUNCTION()
	void OnMinuteChanged(FGameTimeStruct CurrentTime);

protected:
	virtual void BeginPlay() override;

public:
	ATimeBasedDirectionalLight();
};
