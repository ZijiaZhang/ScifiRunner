// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock_Normal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

ARunnerBlock_Normal::ARunnerBlock_Normal():ARunnerBlock() {
	PrimaryActorTick.bCanEverTick = true;
	
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	Floor->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor->AttachTo(RootComponent);
	Floor->SetRelativeLocation(FVector(128.0f,0,0));
	Floor->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));
	

	
	Arrow->SetRelativeLocation(FVector(256, 0, 0));
	
}