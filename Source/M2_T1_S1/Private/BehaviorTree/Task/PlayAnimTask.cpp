// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/PlayAnimTask.h"

#include "Actors/BaseEntityPawn.h"
#include "BehaviorTree/BlackboardComponent.h"

UPlayAnimTask::UPlayAnimTask()
{
	NodeName = TEXT("Play animation");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UPlayAnimTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	targetActor= Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject(TargetKey.SelectedKeyName));
	if (targetActor == nullptr) return EBTNodeResult::Failed;
	meshToAnimate=targetActor->Visual;
	if (meshToAnimate != nullptr) return EBTNodeResult::Failed;
	AnimInstance = meshToAnimate->GetAnimInstance();
	if (AnimInstance == nullptr) return EBTNodeResult::Failed;
	AnimInstance->Montage_Play(AnimationToPlay);
	if (!bWaitForCompletion) return EBTNodeResult::Succeeded;
	return EBTNodeResult::InProgress;
	
	
}

void UPlayAnimTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (BlackboardComp == nullptr) return;
	if (targetActor == nullptr) return;
	if (meshToAnimate != nullptr) return;
	if (AnimInstance == nullptr) return;
	if (!AnimInstance->Montage_IsPlaying(AnimationToPlay))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
	
}
