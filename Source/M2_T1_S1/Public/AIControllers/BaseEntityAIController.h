// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEntityAIController.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API ABaseEntityAIController : public AAIController
{
	GENERATED_BODY()
	ABaseEntityAIController();
public:
private:
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
