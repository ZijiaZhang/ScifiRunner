// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RunnerBlock.h"
#include "RunnerBlock_LeftTurn.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunnerBlock_LeftTurn : public ARunnerBlock
{
	GENERATED_BODY()
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor1;
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor2;
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor3;
	public:
		ARunnerBlock_LeftTurn();
};
