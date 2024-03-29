// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "RunnerBlock_Normal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

ARunnerBlock_Normal::ARunnerBlock_Normal():ARunnerBlock() {
	PrimaryActorTick.bCanEverTick = true;
	
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	Floor->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor->SetRelativeLocation(FVector(128.0f,0,0));
	Floor->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));
	

	
	Arrow->SetRelativeLocation(FVector(256, 0, 0));
	
	spawnTrigger->SetBoxExtent(FVector(20, 128, 128));
	spawnTrigger->SetRelativeLocation(FVector(256, 0, 64));
}