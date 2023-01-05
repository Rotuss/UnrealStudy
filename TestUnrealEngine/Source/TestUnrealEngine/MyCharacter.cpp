// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera_ = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// ������ RootComponent�� �׻� �־��� �� Root�� �������� �������� ����
	// SpringArm_->SetupAttachment() �� �θ� ������ �ϴ��� ��� �ٿ��ְ� �Ǵ� ��
	// ���� ��ǻ� CapsuleComponent�� Root�̱� ����
	SpringArm_->SetupAttachment(GetCapsuleComponent());
	Camera_->SetupAttachment(SpringArm_);

	// SpringArm_ Setting
	// ����
	SpringArm_->TargetArmLength = 500.0f;
	// ����
	SpringArm_->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

	// ��ġ ����. FVector(0.0f, 0.0f, -88.0f) => ����
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh_(TEXT("SkeletalMesh'/Game/ParagonRevenant/Characters/Heroes/Revenant/Meshes/Revenant.Revenant'"));

	if (SkeletalMesh_.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh_.Object);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);
}

void AMyCharacter::UpDown(float _Value)
{
	if (0.0f == _Value)
	{
		return;
	}

	AddMovementInput(GetActorForwardVector(), _Value);
}

void AMyCharacter::LeftRight(float _Value)
{
	if (0.0f == _Value)
	{
		return;
	}

	AddMovementInput(GetActorRightVector(), _Value);
}

void AMyCharacter::Yaw(float _Value)
{
	AddControllerYawInput(_Value);
}
