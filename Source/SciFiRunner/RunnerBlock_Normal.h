// COPYRIGHT 2019 Zijia Zhang All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "RunnerBlock.h"
#include "RunnerBlock_Normal.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunnerBlock_Normal : public ARunnerBlock
{
	GENERATED_BODY()
	UPROPERTY(AdvancedDisplay, EditAnywhere)
		UStaticMeshComponent* Floor;
public:

	ARunnerBlock_Normal();
};
