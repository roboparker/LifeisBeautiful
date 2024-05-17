#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "Seasons.generated.h"

UENUM(BlueprintType)
enum class ESeasons : uint8
{
	DAWNLIGHT UMETA(DisplayName = "Dawnlight"),
	SUNCREST UMETA(DisplayName = "Suncrest"),
	ELDERBLOOM UMETA(DisplayName = "Elderbloom"),
	DUSKTIDE UMETA(DisplayName = "Dusktide")
};
