#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class ABaseEntityPawn;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class M2_T1_S1_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

public:
	ABaseProjectile();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile")
	USphereComponent* CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile")
	UStaticMeshComponent* MeshComponent;
	

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float Speed = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float Damages = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bPassThrough = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float LifeTime = 15.0f;

	ABaseEntityPawn* ownerProjectile;
	int team;

protected:
	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
						 UPrimitiveComponent* OtherComp, FVector NormalImpulse,
						 const FHitResult& Hit);
};
