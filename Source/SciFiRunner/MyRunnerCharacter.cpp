// COPYRIGHT 2019 Zijia Zhang All Rights Reserved


#include "MyRunnerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyRunnerCharacter::AMyRunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyRunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyRunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyRunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyRunnerCharacter::ActivateMask() {
	mask--;
}

void AMyRunnerCharacter::TurnLeft(){
	return TurnLeftInternal();
}

void AMyRunnerCharacter::TurnLeftInternal_Implementation() {
	TargetRotation += FRotator(0.f, -90.f, 0.f);
}

void AMyRunnerCharacter::TurnRight() {
	return TurnRightInternal();
}

void AMyRunnerCharacter::TurnRightInternal_Implementation() {
	TargetRotation += FRotator(0.f, 90.f, 0.f);
}

void AMyRunnerCharacter::Turn() {
	if (GetControlRotation() != TargetRotation) {
		
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetControlRotation(
			FMath::RInterpTo(GetControlRotation(), TargetRotation, UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 15)
		);
	}
}

void AMyRunnerCharacter::MoveForwardAction(float value) {
	
	AddMovementInput(GetCapsuleComponent()->GetForwardVector(), 1);
	Turn();
}

void AMyRunnerCharacter::AddInputBinds() {
	InputComponent->BindAxis("MoveForward", this, &AMyRunnerCharacter::MoveForwardAction);
}

void AMyRunnerCharacter::MoveRightAction(float value) {

	AddMovementInput(GetCapsuleComponent()->GetRightVector(), 1);
	Turn();
}