// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "RunnerBlock_LeftTurn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

ARunnerBlock_LeftTurn::ARunnerBlock_LeftTurn() {
	Floor1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor1"));
	Floor1->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor1->SetRelativeLocation(FVector(128.0f, 0, 0));
	Floor1->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));

	Floor2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor2"));
	Floor2->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor2->SetRelativeLocation(FVector(384.0f, 0, 0));
	Floor2->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));

	Floor3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor3"));
	Floor3->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	Floor3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	Floor3->SetRelativeLocation(FVector(384.0f, -256, 0));
	Floor3->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.2f));

	Arrow->SetRelativeLocation(FVector(384, -256, 0));
	Arrow->SetRelativeRotation(FRotator(0, -90, 0));

	spawnTrigger->SetBoxExtent(FVector(128, 20, 128));
	spawnTrigger->SetRelativeLocation(FVector(384, -256, 64));

}