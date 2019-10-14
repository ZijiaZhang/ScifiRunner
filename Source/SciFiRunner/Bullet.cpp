// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"



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
	MeshComponent->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));
	//MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Partical = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Trail"));
	Partical->SetTemplate(LoadObject<UParticleSystem>(nullptr,TEXT("/Game/ParagonTwinblast/FX/Particles/Abilities/Primary/FX/P_TwinBlast_Primary_Trail.P_TwinBlast_Primary_Trail")));
	
	Partical->SetupAttachment(MeshComponent);
	Partical->SetRelativeScale3D(FVector(40.0f, 40.0f, 40.0f));
	Partical->SetRelativeRotation(FRotator(0, 90, 0));
	Partical->Activate(true);
	speed = 0;
	direction = FVector();
	
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(5.0f);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AddActorWorldOffset(direction*DeltaTime*speed);
}

