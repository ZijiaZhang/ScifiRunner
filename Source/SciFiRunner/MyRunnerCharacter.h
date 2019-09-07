// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyRunnerCharacter.generated.h"

UCLASS()
class SCIFIRUNNER_API AMyRunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyRunnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BluePrintReadWrite)
	int mask = 10;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	FRotator TargetRotation = FRotator(0.f, -90.f,0.f);
	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "TurnLeft"))
		void TurnLeftInternal();
	void TurnLeftInternal_Implementation();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void ActivateMask();
	UFUNCTION(BlueprintCallable)
	void TurnLeft();
};
