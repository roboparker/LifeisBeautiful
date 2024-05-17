﻿#pragma once

#include "CoreMinimal.h"
#include "FGameTimeStruct.generated.h"

enum class EDays : uint8;
enum class ESeasons : uint8;

USTRUCT(BlueprintType)
struct FGameTimeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	int32 Year;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	int Season;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	int Day;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	int Hour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	int Minute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Time")
	float Second;

	void AddSeconds(float Seconds);

	void AddTime(const FGameTimeStruct& Time);

	ESeasons GetSeasonOfYear() const;

	EDays GetDayOfWeek() const;

	bool operator==(const FGameTimeStruct& Other) const;

	bool operator<(const FGameTimeStruct& Other) const;
	
	bool operator<=(const FGameTimeStruct& Other) const;

	bool operator>(const FGameTimeStruct& Other) const;

	bool operator>=(const FGameTimeStruct& Other) const;

	FGameTimeStruct operator+(const FGameTimeStruct& Other) const;

	FGameTimeStruct operator+(const float Seconds) const;

private:
	void Normalize();
};