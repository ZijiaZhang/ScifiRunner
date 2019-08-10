// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunnerBlock.generated.h"
UCLASS(config = Game)
class SCIFIRUNNER_API ARunnerBlock : public AActor
{
	GENERATED_BODY()
	public:	
		// Sets default values for this actor's properties
		ARunnerBlock();
		UPROPERTY(AdvancedDisplay, EditAnywhere)
			class UArrowComponent* Arrow;
		UPROPERTY(AdvancedDisplay, EditAnywhere)
			class UBoxComponent* spawnTrigger;
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		UFUNCTION()
		void triggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	public:	
		// Called every frame
		virtual void Tick(float DeltaTime) override;
		FVector getNextLocation();
		FRotator getNextRotation();
		UFUNCTION()
		void DestroySelf();
};
