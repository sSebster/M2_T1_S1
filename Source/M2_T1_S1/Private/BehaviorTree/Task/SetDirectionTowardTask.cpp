// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetDirectionTowardTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetDirectionTowardTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	AActor* entity=Cast<AActor>(BlackboardComp->GetValueAsObject("SelfActor"));
	FVector directionToGo= (entity->GetActorForwardVector()*Direction.X + entity->GetActorRightVector()*Direction.Y);
	FVector TargetLocation = entity->GetActorLocation() + directionToGo;
	BlackboardComp->SetValueAsVector("Direction",TargetLocation);
	return EBTNodeResult::Succeeded;
}
