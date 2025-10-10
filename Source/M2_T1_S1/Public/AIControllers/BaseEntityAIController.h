// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
private:
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

	
	UFUNCTION(BlueprintCallable, Category = "AI")
	void StartAI();
	UFUNCTION(BlueprintCallable, Category = "AI")
	void StopAI();

	UBlackboardComponent* BlackboardComponent;
	UBehaviorTreeComponent* BehaviorTreeComponent;
	
};
