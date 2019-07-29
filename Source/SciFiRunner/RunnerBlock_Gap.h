// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RunnerBlock.h"
#include "RunnerBlock_Gap.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunnerBlock_Gap : public ARunnerBlock
{
	GENERATED_BODY()
	public:
		ARunnerBlock_Gap();
		UPROPERTY(AdvancedDisplay, EditAnywhere)
			UStaticMeshComponent* Floor1;
		UPROPERTY(AdvancedDisplay, EditAnywhere)
			UStaticMeshComponent* Floor2;
};
