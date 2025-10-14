// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class GameTargetType:uint8
{
	Ally UMETA(DisplayName = "Ally"),
	Ennemy UMETA(DisplayName = "Ennemy"),
};
