// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ARunnerBlock::ARunnerBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	RootComponent = Floor;
}

// Called when the game starts or when spawned
void ARunnerBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunnerBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

