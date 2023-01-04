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
// == Start()
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 시작
	// 카테고리, 로깅 수준, 형식, 인자
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
// == Update()
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// DeltaTime : 컴퓨터마다 게임이 돌아가는 속도가 다름. 200프레임이 돌아간다고 할 경우 1초 동안 Tick이 200번 돌아간다고 보면 됨.
	// 즉 컴퓨터 환경에 따라 같은 시간에 Tick 호출되는 수가 다름. DeltaTime은 이러한 Tick 사이의 경과 시간. 따라서 대부분이 이동과 관련된 것에는 DeltaTime을 곱해주는 것이 자연스러움

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);

	// Unity 혹은 DirectX를 통해 Local과 World의 차이를 알 수 있음. Unreal도 마찬가지
	// Pitch : Y축 대상으로 회전
	// Roll : X축 대상으로 회전
	// Yaw : Z축 대상으로 회전
	AddActorLocalRotation(FRotator(0.0f, RotateSpeed_ * DeltaTime, 0.0f));
}

