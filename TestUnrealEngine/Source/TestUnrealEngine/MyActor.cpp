// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh_;
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh_(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	// ���� StaticMesh_�ε带 �����ߴٸ�
	if (StaticMesh_.Succeeded())
	{
		// �ε��� ���ҽ��� SetStaticMesh�Լ��� ���� �־��� 
		Mesh_->SetStaticMesh(StaticMesh_.Object);
	}
}

// Called when the game starts or when spawned
// == Start()
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// ����
	// ī�װ�, �α� ����, ����, ����
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
// == Update()
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// DeltaTime : ��ǻ�͸��� ������ ���ư��� �ӵ��� �ٸ�. 200�������� ���ư��ٰ� �� ��� 1�� ���� Tick�� 200�� ���ư��ٰ� ���� ��.
	// �� ��ǻ�� ȯ�濡 ���� ���� �ð��� Tick ȣ��Ǵ� ���� �ٸ�. DeltaTime�� �̷��� Tick ������ ��� �ð�. ���� ��κ��� �̵��� ���õ� �Ϳ��� DeltaTime�� �����ִ� ���� �ڿ�������

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);

	// Unity Ȥ�� DirectX�� ���� Local�� World�� ���̸� �� �� ����. Unreal�� ��������
	// Pitch : Y�� ������� ȸ��
	// Roll : X�� ������� ȸ��
	// Yaw : Z�� ������� ȸ��
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed_ * DeltaTime, 0.0f));
}

