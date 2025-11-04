// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/PlayVFXTask.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UPlayVFXTask::UPlayVFXTask()
{
	NodeName = TEXT("Play VFX");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UPlayVFXTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	AActor* targetActor= Cast<AActor>(BlackboardComp->GetValueAsObject(TargetKey.SelectedKeyName));
	if (targetActor == nullptr) return EBTNodeResult::Failed;
	UGameplayStatics::SpawnEmitterAtLocation(
		targetActor->GetWorld(),
		VFXToPlay,
		targetActor->GetActorLocation(),
		targetActor->GetActorRotation(),
		Scale
	);
	return EBTNodeResult::Succeeded;
}
