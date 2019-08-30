// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "MainPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyRunnerCharacter.h"

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	InputComponent->BindTouch(IE_Pressed, this, &AMainPlayerController::Touched);
}

void AMainPlayerController::Touched(ETouchIndex::Type TouchIndex, FVector Location)
{
	AMyRunnerCharacter* myCharacter = (AMyRunnerCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	myCharacter->ActivateMask();
}