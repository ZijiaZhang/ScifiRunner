// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyRunnerCharacter.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	void Pressed(ETouchIndex::Type FingerIndex, FVector Location);
	void Released(ETouchIndex::Type FingerIndex, FVector Location);
	UFUNCTION(BlueprintCallable)
	void SetupPlayerCharacter();
private:
	bool isPressing = false;
	FVector2D InitialTouchLocation;
	FVector2D FinalTouchLocation;
	AMyRunnerCharacter* myCharacter;
	bool once = true;
};
