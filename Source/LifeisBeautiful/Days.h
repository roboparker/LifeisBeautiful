#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "Days.generated.h"

UENUM(BlueprintType)
enum class EDays : uint8
{
	LUMIN UMETA(DisplayName = "Lumin"),
	TERRAN UMETA(DisplayName = "Terran"),
	AQUAEN UMETA(DisplayName = "Aquaen"),
	SYLVAN UMETA(DisplayName = "Sylvan"),
	PYRON UMETA(DisplayName = "Pyron"),
	UMBRA UMETA(DisplayName = "Umbra"),
};
