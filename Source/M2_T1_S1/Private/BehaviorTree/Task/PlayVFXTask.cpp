// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/PlayVFXTask.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

UPlayVFXTask::UPlayVFXTask()
{
	NodeName = TEXT("Play VFX");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UPlayVFXTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	AActor* targetActor= Cast<AActor>(BlackboardComp->GetValueAsObject(TargetKey.SelectedKeyName));
	if (targetActor == nullptr) return EBTNodeResult::Failed;
	UParticleSystemComponent* SpawnedVFX = UGameplayStatics::SpawnEmitterAtLocation(
		targetActor->GetWorld(),
		VFXToPlay,
		targetActor->GetActorLocation(),
		targetActor->GetActorRotation(),
		Scale,
		true
	);
	if (SpawnedVFX == nullptr) return EBTNodeResult::Failed;

	if (SpawnedVFX && LifeTime > 0.f)
	{
		// Détruire le composant après LifeTime secondes
		FTimerHandle TimerHandle;
		targetActor->GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			[SpawnedVFX]()
			{
				if (SpawnedVFX)
				{
					SpawnedVFX->DestroyComponent();
				}
			},
			LifeTime,
			false
		);
	}
	
	return EBTNodeResult::Succeeded;
}
