// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseProjectilePawn.h"

// Sets default values
ABaseProjectilePawn::ABaseProjectilePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseProjectilePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectilePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseProjectilePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

