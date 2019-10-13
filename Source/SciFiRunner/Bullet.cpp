// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/EngineMeshes/Cube")));
	SetRootComponent(MeshComponent);
	//MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	MeshComponent->SetRelativeLocation(FVector(128.0f, 0, 0));
	MeshComponent->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	//MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	speed = 0;
	direction = FVector();
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AddActorWorldOffset(direction*DeltaTime*speed);
}

