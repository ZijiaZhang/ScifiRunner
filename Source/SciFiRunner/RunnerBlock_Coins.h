// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RunnerBlock_Normal.h"
#include "Coins.h"
#include "RunnerBlock_Coins.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunnerBlock_Coins : public ARunnerBlock_Normal
{
	GENERATED_BODY()
	public:
		ARunnerBlock_Coins();
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
			TArray<ACoins*> Coins;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
			class UBoxComponent* spawnArea;
		virtual void BeginPlay() override;
	private:
		void spawnCoins();
	
};
