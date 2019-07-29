// Fill out your copyright notice in the Description page of Project Settings.


#include "RunGameMode.h"
#include "RunnerBlock.h"
#include "Engine/World.h"
#include <stdlib.h>
#include "RunnerBlock_Normal.h"


void ARunGameMode::BeginPlay() {
	for (int i = 0; i < 10; i++) {
		SpawnInitialBlock();
	}
}

void ARunGameMode::SpawnNewBlock() {
	if (AllBlocks.Num() == 0)
		return;
	FActorSpawnParameters SpawnInfo;

	int randInt = rand() % AllBlocks.Num();
	
	ARunnerBlock* block = GetWorld()->SpawnActor<ARunnerBlock>(AllBlocks[randInt],Location, Rotation,SpawnInfo);
	Location = block->getNextLocation();
	Rotation = block->getNextRotation();
}

void ARunGameMode::SpawnInitialBlock() {
	FActorSpawnParameters SpawnInfo;

	int randInt = rand() % AllBlocks.Num();

	ARunnerBlock_Normal* block = GetWorld()->SpawnActor<ARunnerBlock_Normal> (Location, Rotation, SpawnInfo);
	Location = block->getNextLocation();
	Rotation = block->getNextRotation();
}