// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class TESTUNREALENGINE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// Actor에는 없지만 Pawn에는 만들자마자 기본적으로 있는 함수
	// 입력을 받아 움직일 수 있는 함수라고 볼 수 있음
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpDown(float _Value);
	void LeftRight(float _Value);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh_;
	
	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* Movement_;
};
