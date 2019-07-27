// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock_Coins.h"
#include "Components/BoxComponent.h"
#include "Coins.h"
#include "Engine/World.h"
#include <stdlib.h>

ARunnerBlock_Coins::ARunnerBlock_Coins() {
	spawnArea = CreateDefaultSubobject<UBoxComponent>("SpawnArea");
	spawnArea->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	spawnArea->SetBoxExtent(FVector(128, 128, 10));
	spawnArea->SetRelativeLocation(FVector(128, 0, 30));
}

void ARunnerBlock_Coins::spawnCoins() {
	FVector Location(rand() % 128 -64 , rand() % 128 -64, 30);
	ACoins* coin = GetWorld()->SpawnActor<ACoins>(Location + spawnArea->GetComponentLocation(), FRotator(0, 0, 0));
}

void ARunnerBlock_Coins::BeginPlay() {
	spawnCoins();
}