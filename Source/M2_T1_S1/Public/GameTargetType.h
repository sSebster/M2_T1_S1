// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameTargetType.generated.h"

UENUM(BlueprintType)
enum class EGameTargetType  : uint8
{
	Ally=0 UMETA(DisplayName = "Ally"),
	Ennemy=1 UMETA(DisplayName = "Ennemy"),
};
