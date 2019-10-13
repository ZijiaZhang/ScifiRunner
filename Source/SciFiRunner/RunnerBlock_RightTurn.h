// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RunnerBlock.h"
#include "RunnerBlock_RightTurn.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunnerBlock_RightTurn : public ARunnerBlock
{
	GENERATED_BODY()
		UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor1;
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor2;
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor3;
public:
	ARunnerBlock_RightTurn();
};
