// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SpawnProjectilTask.h"

USpawnProjectilTask::USpawnProjectilTask()
{
	NodeName = TEXT("Spawn projectile");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}