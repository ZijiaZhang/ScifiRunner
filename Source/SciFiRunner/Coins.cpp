// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RunGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Coin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	Coin->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Meshes/RotationHandleFull")));
	RootComponent = Coin;
	Coin->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Coin->SetWorldScale3D(FVector(0.2, 0.2, 0.2));
	Coin->OnComponentBeginOverlap.AddDynamic(this, &ACoins::collectCoin);

	/*collisionTrigger = CreateDefaultSubobject<UBoxComponent>("collect");
	collisionTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	collisionTrigger->SetGenerateOverlapEvents(true);
	collisionTrigger->SetBoxExtent(FVector(30, 100, 100));
	collisionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACoins::collectCoin);*/
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoins::collectCoin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor == (AActor*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)) {
		((ARunGameMode*)GetWorld()->GetAuthGameMode())->SpawnNewBlock();
		GEngine->AddOnScreenDebugMessage(-1, 3.0F, FColor::Yellow, TEXT("Coin Collected"));
		GetWorld()->DestroyActor(this);
	}

}

