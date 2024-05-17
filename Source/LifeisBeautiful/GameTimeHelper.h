#pragma once

#include "CoreMinimal.h"
#include "FGameTimeStruct.h"
#include "UObject/Object.h"
#include "GameTimeHelper.generated.h"

UCLASS(BlueprintType, Category = "GameTime")
class LIFEISBEAUTIFUL_API UGameTimeHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Time")
	static bool IsLessThan(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A < B;
	}

	UFUNCTION(BlueprintPure, Category = "Time")
	static bool IsEqualTo(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A == B;
	}

	UFUNCTION(BlueprintPure, Category = "Time")
	static bool IsGreaterThan(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A > B;
	}

	UFUNCTION(BlueprintPure, Category = "Game Time")
	static bool IsLessThanOrEqualTo(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A <= B;
	}

	UFUNCTION(BlueprintPure, Category = "Game Time")
	static bool IsGreaterThanOrEqualTo(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A >= B;
	}
	
	UFUNCTION(BlueprintPure, Category = "Game Time")
	static FGameTimeStruct AddTimeStructs(const FGameTimeStruct& A, const FGameTimeStruct& B)
	{
		return A + B;
	}

	UFUNCTION(BlueprintPure, Category = "Game Time")
	static FGameTimeStruct AddSecondsToTimeStruct(const FGameTimeStruct& Time, float Seconds)
	{
		return Time + Seconds;
	}
};
