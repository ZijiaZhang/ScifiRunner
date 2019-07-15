// Fill out your copyright notice in the Description page of Project Settings.

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
