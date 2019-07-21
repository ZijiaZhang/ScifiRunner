// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "RunGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARunnerBlock::ARunnerBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<UPrimitiveComponent>("Root");
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->AttachTo(RootComponent);

	spawnTrigger = CreateDefaultSubobject<UBoxComponent>("nextSpwan");
	spawnTrigger->AttachTo(RootComponent);
	spawnTrigger->SetGenerateOverlapEvents(true);
	
}

// Called when the game starts or when spawned
void ARunnerBlock::BeginPlay()
{
	Super::BeginPlay();
	spawnTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARunnerBlock::triggerOverlap);
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

void ARunnerBlock::triggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
		if (OtherActor == (AActor*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)) {
			((ARunGameMode*)GetWorld()->GetAuthGameMode())->SpawnNewBlock();
			UE_LOG(LogTemp, Warning, TEXT("Success"));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No"));
		}
}

