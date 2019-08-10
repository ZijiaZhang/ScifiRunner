// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "RunGameMode.h"
#include "RunnerBlock.h"
#include "Engine/World.h"
#include <stdlib.h>
#include "RunnerBlock_Normal.h"


void ARunGameMode::BeginPlay() {
	for (int i = 0; i < 2; i++) {
		SpawnInitialBlock();
	}
	for (int i = 0; i < 20; i++) {
		SpawnNewBlock();
	}
}

void ARunGameMode::SpawnNewBlock() {
	if (blockCount > 10) {
		SpawnTurnBlock();
		blockCount = 0;
	}
	else
		SpawnNormalBlock();
	blockCount++;
}

void ARunGameMode::SpawnInitialBlock() {
	FActorSpawnParameters SpawnInfo;

	int randInt = rand() % AllBlocks.Num();

	ARunnerBlock_Normal* block = GetWorld()->SpawnActor<ARunnerBlock_Normal> (Location, Rotation, SpawnInfo);
	Location = block->getNextLocation();
	Rotation = block->getNextRotation();
}


void ARunGameMode::SpawnNormalBlock() {
	if (AllBlocks.Num() == 0)
		return;
	FActorSpawnParameters SpawnInfo;

	int randInt = rand() % AllBlocks.Num();

	ARunnerBlock* block = GetWorld()->SpawnActor<ARunnerBlock>(AllBlocks[randInt], Location, Rotation, SpawnInfo);
	Location = block->getNextLocation();
	Rotation = block->getNextRotation();
}

void ARunGameMode::SpawnTurnBlock() {
	if (TurnBlocks.Num() == 0)
		return;
	FActorSpawnParameters SpawnInfo;

	int randInt = rand() % TurnBlocks.Num();

	ARunnerBlock* block = GetWorld()->SpawnActor<ARunnerBlock>(TurnBlocks[randInt], Location, Rotation, SpawnInfo);
	Location = block->getNextLocation();
	Rotation = block->getNextRotation();
}