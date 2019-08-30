// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void SetupInputComponent() override;
	void Touched(ETouchIndex::Type FingerIndex, FVector Location);
};
