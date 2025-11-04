#include "BehaviorTree/Task/SetDirectionTowardTask.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BehaviorTree/BlackboardComponent.h"

USetDirectionTowardTask::USetDirectionTowardTask()
{
	bNotifyTick = true;
}

EBTNodeResult::Type USetDirectionTowardTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	APawn* Pawn = Cast<APawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (!Pawn) return EBTNodeResult::Failed;

	
	if (!Pawn->GetMovementComponent() || !Pawn->GetMovementComponent()->IsA<UFloatingPawnMovement>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn n'a pas de FloatingPawnMovement!"));
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::InProgress; // On continue à tick
}

void USetDirectionTowardTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return;

	APawn* Pawn = Cast<APawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (!Pawn) return;

	
	FVector DirectionVector = (Pawn->GetActorForwardVector() * Direction.X +
							   Pawn->GetActorRightVector() * Direction.Y).GetSafeNormal();

	
	Pawn->AddMovementInput(DirectionVector, Speed * DeltaSeconds);
}

void USetDirectionTowardTask::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	
}
