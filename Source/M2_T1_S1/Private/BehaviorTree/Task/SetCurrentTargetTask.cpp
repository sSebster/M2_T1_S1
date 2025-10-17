// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetCurrentTargetTask.h"

#include "Actors/BaseEntityPawn.h"
#include "AIControllers/BaseEntityAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USetCurrentTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	ABaseEntityPawn* Entity = Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject(FName("SelfActor")));
	if (Entity == nullptr) return EBTNodeResult::Failed;
	ABaseEntityAIController* AIController = Cast<ABaseEntityAIController>(Entity->GetController());
	if (AIController == nullptr) return EBTNodeResult::Failed;
	UWorld* World = OwnerComp.GetWorld();
	if (World == nullptr) return EBTNodeResult::Failed;
	AMainGamemode* MainGamemode = Cast<AMainGamemode>(UGameplayStatics::GetGameMode(World));
	if (MainGamemode == nullptr) return EBTNodeResult::Failed;
	int currentTeam= BlackboardComp->GetValueAsInt(FName("Team"));
	
	TPair<ABaseEntityPawn*,float> closest;
	closest.Value=INFINITY;
	for (ABaseEntityPawn* EntityEnemy : getEnemyTeam(currentTeam,MainGamemode))
		{
			float distance = (EntityEnemy->GetDistanceTo(Entity));
			if (distance < closest.Value)
			{
				closest.Value=distance;
				closest.Key=EntityEnemy;
			}
		}
	
	BlackboardComp->SetValueAsObject(FName("CurrentTarget"),closest.Key);
	return EBTNodeResult::Succeeded;
}

TArray<ABaseEntityPawn*> USetCurrentTargetTask::getEnemyTeam(int myTeam,AMainGamemode* MainGamemode)
{
	if (myTeam == 1)
	{
		return MainGamemode->Team2Entity;
	}
	return MainGamemode->Team1Entity; 
}
