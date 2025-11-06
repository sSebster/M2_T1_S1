#include "Actors/BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "AIControllers/BaseEntityAIController.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	// === Composant de collision ===
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(10.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnProjectileHit);
	RootComponent = CollisionComponent;

	// === Mouvement du projectile ===
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f; // pas de gravité

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CollisionComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
	SetLifeSpan(LifeTime);
}

void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseProjectile::OnProjectileHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
									  UPrimitiveComponent* OtherComp, FVector NormalImpulse,
									  const FHitResult& Hit)
{
	if (!OtherActor || OtherActor == this)
		return;
	
	ABaseEntityAIController* AIController = Cast<ABaseEntityAIController>(OtherActor->GetInstigatorController());
	if (AIController)
	{
		UBlackboardComponent* Blackboard = AIController->GetBlackboardComponent();
		if (Blackboard && Blackboard->IsValidKey(Blackboard->GetKeyID("PV")))
		{
			float PV = Blackboard->GetValueAsFloat("PV");
			PV -= Damages;
			Blackboard->SetValueAsFloat("PV", PV);
		}
	}
	
	if (!bPassThrough)
	{
		Destroy();
	}
}
