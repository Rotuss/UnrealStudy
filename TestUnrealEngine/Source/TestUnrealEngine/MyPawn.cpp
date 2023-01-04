// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Movement_ = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	RootComponent = Mesh_;
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh_(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (StaticMesh_.Succeeded())
	{
		Mesh_->SetStaticMesh(StaticMesh_.Object);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
}

void AMyPawn::UpDown(float _Value)
{
	if (0.0f == _Value)
	{
		return;
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), _Value);
	AddMovementInput(GetActorForwardVector(), _Value);
}

void AMyPawn::LeftRight(float _Value)
{
	if (0.0f == _Value)
	{
		return;
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), _Value);
	AddMovementInput(GetActorRightVector(), _Value);
}

