// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerBlock.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "RunGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values
ARunnerBlock::ARunnerBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<UArrowComponent>("Root");
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	spawnTrigger = CreateDefaultSubobject<UBoxComponent>("nextSpwan");
	spawnTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	spawnTrigger->SetGenerateOverlapEvents(true);
	spawnTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARunnerBlock::triggerOverlap);
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

void ARunnerBlock::triggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
		if (OtherActor == (AActor*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)) {
			((ARunGameMode*)GetWorld()->GetAuthGameMode())->SpawnNewBlock();
			FTimerHandle MemberTimerHandle;
		GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ARunnerBlock::DestroySelf, 2.0f, false,3.0f);
		}
		
}

void ARunnerBlock::DestroySelf() {
	Destroy();
}

