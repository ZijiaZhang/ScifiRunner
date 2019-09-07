// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "MainPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	InputComponent->BindTouch(IE_Pressed, this, &AMainPlayerController::Pressed);
	InputComponent->BindTouch(IE_Released, this, &AMainPlayerController::Released);
	
	
}

void AMainPlayerController::Pressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	isPressing = true;
	
	GetInputTouchState(ETouchIndex::Touch1,InitialTouchLocation.X, InitialTouchLocation.Y, isPressing);
	//myCharacter->ActivateMask();
}

void AMainPlayerController::Released(ETouchIndex::Type FingerIndex, FVector Location) {
	isPressing = false;
	once = true;
	//FinalTouchLocation = Location;

}

void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bool isCurrentlyPressed;
	GetInputTouchState(ETouchIndex::Touch1, FinalTouchLocation.X, FinalTouchLocation.Y, isCurrentlyPressed);
	if (isPressing && (FinalTouchLocation - InitialTouchLocation).Size() > 100 && once) {
		FVector2D Offset = FinalTouchLocation - InitialTouchLocation;
		if (FMath::Abs(Offset.X) > FMath::Abs(Offset.Y) && Offset.X < 0) {
			if(myCharacter)
				myCharacter->TurnLeft();
		}
		once = false;
	}
}

void AMainPlayerController::SetupPlayerCharacter(){
	myCharacter = (AMyRunnerCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}