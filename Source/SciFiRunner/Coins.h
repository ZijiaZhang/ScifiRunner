// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coins.generated.h"

UCLASS()
class SCIFIRUNNER_API ACoins : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoins();
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Coin;
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		class UBoxComponent* collisionTrigger;
	UFUNCTION()
	void collectCoin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
