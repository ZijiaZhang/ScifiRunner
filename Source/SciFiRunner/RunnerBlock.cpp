// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock.h"
#include "Components/ArrowComponent.h"

// Sets default values
ARunnerBlock::ARunnerBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<UPrimitiveComponent>("Root");
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->AttachTo(RootComponent);
	
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

FVector ARunnerBlock::getNextLocation() {
	return Arrow->GetComponentLocation();
}

FRotator ARunnerBlock::getNextRotation() {
	return Arrow->GetComponentRotation();
}

