// COPYRIGHT 2019 Zijia Zhang All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RunGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SCIFIRUNNER_API ARunGameMode : public AGameMode
{
	GENERATED_BODY()
	private:
		FVector Location = FVector(0.0f);
		FRotator Rotation = FRotator(0.0f,-90.0f,0.0f);
		void SpawnNormalBlock();
		void SpawnTurnBlock();
		int blockCount = 0;
		
	public:
		void SpawnNewBlock();
		void SpawnInitialBlock();
		
		virtual void BeginPlay() override;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		TArray< TSubclassOf<class ARunnerBlock>> AllBlocks;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
			TArray< TSubclassOf<class ARunnerBlock>> TurnBlocks;
};
