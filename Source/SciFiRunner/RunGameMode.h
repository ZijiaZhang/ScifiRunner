// Fill out your copyright notice in the Description page of Project Settings.

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
		FRotator Rotation = FRotator(0.0f);
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
