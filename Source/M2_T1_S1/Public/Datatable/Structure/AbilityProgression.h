// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityProgression.generated.h"

/**
 * 
 */
USTRUCT()
struct M2_T1_S1_API FAbilityProgression : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Ability)
	int level;
};
