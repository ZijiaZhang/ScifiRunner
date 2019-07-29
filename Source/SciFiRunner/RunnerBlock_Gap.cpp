//COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "RunnerBlock_Gap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
ARunnerBlock_Gap::ARunnerBlock_Gap() {
	Arrow->SetRelativeLocation(FVector(256*3, 0, 0));

	spawnTrigger->SetBoxExtent(FVector(20, 128, 128));
	spawnTrigger->SetRelativeLocation(FVector(256*3, 0, 64));

	Floor1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor1"));
	Floor1->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor1->SetRelativeLocation(FVector(128.0f, 0, 0));
	Floor1->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));

	Floor2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor2"));
	Floor2->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor2->SetRelativeLocation(FVector(128.0f + 256*2, 0, 0));
	Floor2->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));
}