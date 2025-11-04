// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEntityPawn.generated.h"
class UFloatingPawnMovement;


UCLASS()

class M2_T1_S1_API ABaseEntityPawn : public APawn
{
	GENERATED_BODY()
	

public:
	// Sets default values for this pawn's properties
	ABaseEntityPawn();

private:
	
	void InitAbilityTimers();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Projectile")
	FVector ProjectileSpawnLocation;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Abilities")
	int numbersOfAbilities=0;
	
	TArray<FTimerHandle> AbilitiesTimers;

	UPROPERTY(EditAnywhere,Category="Visual")
	USkeletalMeshComponent* Visual;
	UPROPERTY(EditAnywhere,Category="Component")
	UFloatingPawnMovement* FloatingPawnMovement;

};
