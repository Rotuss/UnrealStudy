// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	// AMyPawn에 있는 StaticClass()가 생기고 하나의 Static 객체를 받아 넣어주는 작업
	DefaultPawnClass = AMyPawn::StaticClass();
}