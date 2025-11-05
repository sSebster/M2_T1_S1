// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/DebugAddToTeamTask.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UDebugAddToTeamTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	ABaseEntityPawn* selfActor= Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (selfActor == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load actor"))
		return EBTNodeResult::Failed;
	}
	UWorld* World = OwnerComp.GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load world"))
		return EBTNodeResult::Failed;
	}
	AMainGamemode* MainGamemode = Cast<AMainGamemode>(UGameplayStatics::GetGameMode(World));
	if (MainGamemode == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load gamemode"))
		return EBTNodeResult::Failed;
	}
	switch (value)
	{
		case 1:
			MainGamemode->Team1Entity.Add(selfActor);
		break;
		case 2:
			MainGamemode->Team2Entity.Add(selfActor);
		break;
		default:
			MainGamemode->Team1Entity.Add(selfActor);
		break;
	}
	UE_LOG(LogTemp, Log, TEXT("task add team finished"));
	return EBTNodeResult::Succeeded;
	
}
