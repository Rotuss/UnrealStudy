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
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

