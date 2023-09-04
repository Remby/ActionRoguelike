// Fill out your copyright notice in the Description page of Project Settings.


#include "NCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework//SpringArmComponent.h"

// Sets default values
ANCharacter::ANCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ANCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void ANCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ANCharacter::MoveForward);
	PlayerInputComponent->BindAxis("RotateYaw", this, &APawn::AddControllerYawInput);
}

