// Fill out your copyright notice in the Description page of Project Settings.


#include "RunGameMode.h"
#include "RunnerBlock.h"
#include "Engine/World.h"

void ARunGameMode::SpawnNewBlock() {
	FActorSpawnParameters SpawnInfo;
	ARunnerBlock* block = GetWorld()->SpawnActor<ARunnerBlock>(Location, Rotation, SpawnInfo);
}