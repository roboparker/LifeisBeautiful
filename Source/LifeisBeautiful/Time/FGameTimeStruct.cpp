#include "FGameTimeStruct.h"

void FGameTimeStruct::AddSeconds(float Seconds)
{
	Second += Seconds;
	Normalize();
}

void FGameTimeStruct::AddTime(const FGameTimeStruct& Time)
{
}

ESeasons FGameTimeStruct::GetSeasonOfYear() const
{
	return static_cast<ESeasons>(Season);
}

EDays FGameTimeStruct::GetDayOfWeek() const
{
	return static_cast<EDays>(Day % 7);
}

bool FGameTimeStruct::operator==(const FGameTimeStruct& Other) const
{
	return Year == Other.Year
	&& Season == Other.Season
	&& Day == Other.Day
	&& Hour == Other.Hour
	&& Minute == Other.Minute
	&& Second == Other.Second;
}

bool FGameTimeStruct::operator<(const FGameTimeStruct& Other) const
{
	if (Year != Other.Year)
		return Year < Other.Year;
	if (Season != Other.Season)
		return Season < Other.Season;
	if (Day != Other.Day)
		return Day < Other.Day;
	if (Hour != Other.Hour)
		return Hour < Other.Hour;
	if (Minute != Other.Minute)
		return Minute < Other.Minute;
	return Second < Other.Second;
}

bool FGameTimeStruct::operator<=(const FGameTimeStruct& Other) const
{
	return *this < Other || *this == Other;
}

bool FGameTimeStruct::operator>(const FGameTimeStruct& Other) const
{
	return !(*this < Other) && *this != Other;
}

bool FGameTimeStruct::operator>=(const FGameTimeStruct& Other) const
{
	return !(*this < Other) && *this != Other;
}

FGameTimeStruct FGameTimeStruct::operator+(const FGameTimeStruct& Other) const
{
	FGameTimeStruct Result;
	Result.Year = this->Year + Other.Year;
	Result.Season = this->Season + Other.Season;
	Result.Day = this->Day + Other.Day;
	Result.Hour = this->Hour + Other.Hour;
	Result.Minute = this->Minute + Other.Minute;
	Result.Second = this->Second + Other.Second;
	Result.Normalize();

	return Result;
}

FGameTimeStruct FGameTimeStruct::operator+(const float Seconds) const
{
	FGameTimeStruct Result = *this;
	Result.AddSeconds(Seconds);
	return Result;
}

void FGameTimeStruct::Normalize()
{
	while(Second >= 60)
	{
		Second -= 60;
		Minute++;
	}

	while(Minute >= 60)
	{
		Minute -= 60;
		Hour++;
	}

	while(Hour >= 24)
	{
		Hour -= 24;
		Day++;
	}

	while(Day >= 30)
	{
		Day -= 30;
		Season++;
	}

	while(Season >= 4)
	{
		Season -= 4;
		Year++;
	}
}
