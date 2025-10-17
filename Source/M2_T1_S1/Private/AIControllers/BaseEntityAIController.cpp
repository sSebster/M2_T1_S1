// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllers/BaseEntityAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"


ABaseEntityAIController::ABaseEntityAIController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

TArray<ABaseEntityPawn*> ABaseEntityAIController::getTargets()
{
	return listTargets;
}

void ABaseEntityAIController::AddTargetToList(ABaseEntityPawn* TargetPawn)
{
	if (!listTargets.Contains(TargetPawn)) listTargets.Add(TargetPawn);
}

void ABaseEntityAIController::clearTargetsList()
{
	listTargets.Empty();
}

void ABaseEntityAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	StartAI();
	
}

void ABaseEntityAIController::OnUnPossess()
{
	Super::OnUnPossess();
	StopAI();
}

void ABaseEntityAIController::StartAI()
{
	if (!BehaviorTree || !BehaviorTree->BlackboardAsset) return;

	if (UseBlackboard(BehaviorTree->BlackboardAsset, BlackboardComponent))
	{
		BehaviorTreeComponent->StartTree(*BehaviorTree);
		UE_LOG(LogTemp, Warning, TEXT("behavior tree init"));
	}
}

void ABaseEntityAIController::StopAI()
{
	if (BehaviorTreeComponent)
	{
		BehaviorTreeComponent->StopTree();
		UE_LOG(LogTemp, Warning, TEXT("behavior tree stoped"));
	}
}


