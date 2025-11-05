// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Actors/BaseEntityPawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
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
	TArray<ABaseEntityPawn*> getTargets();
	void AddTargetToList(ABaseEntityPawn* Pawn);
	void clearTargetsList();
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

	
	UFUNCTION(BlueprintCallable, Category = "AI")
	void StartAI();
	UFUNCTION(BlueprintCallable, Category = "AI")
	void StopAI();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	TArray<ABaseEntityPawn*> listTargets;

	UBlackboardComponent* BlackboardComponent;
	UBehaviorTreeComponent* BehaviorTreeComponent;
	
};
