// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class SCIFIRUNNER_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	UPROPERTY(BlueprintReadWrite)
	FVector direction;
	UPROPERTY(BlueprintReadWrite)
	float speed;
	UStaticMeshComponent* MeshComponent;
	UParticleSystemComponent* Partical;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
