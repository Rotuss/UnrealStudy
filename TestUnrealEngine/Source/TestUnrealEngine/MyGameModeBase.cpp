// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	// AMyPawn�� �ִ� StaticClass()�� ����� �ϳ��� Static ��ü�� �޾� �־��ִ� �۾�
	DefaultPawnClass = AMyCharacter::StaticClass();
}