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
	//Value of the oxigen mask.
	UPROPERTY(EditAnywhere,BluePrintReadWrite)
	int mask = 10;
	//The target Location that player aims to.
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	FRotator TargetRotation = FRotator(0.f, -90.f,0.f);
	////////////
	//The Real TurnLeft Function, can be override in blueprint
	////////////
	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "TurnLeft"))
		void TurnLeftInternal();
	void TurnLeftInternal_Implementation();
	////////////
	//The Real TurnRight Function, can be override in blueprint
	////////////
	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "TurnLeft"))
		void TurnRightInternal();
	void TurnRightInternal_Implementation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Activate one mask
	virtual void ActivateMask();
	UFUNCTION(BlueprintCallable)
	void TurnLeft();
	UFUNCTION(BlueprintCallable)
	void TurnRight();
};
