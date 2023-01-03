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

	// 만약 StaticMesh_로드를 성공했다면
	if (StaticMesh_.Succeeded())
	{
		// 로드한 리소스를 SetStaticMesh함수를 통해 넣어줌 
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

