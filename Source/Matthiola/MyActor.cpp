// Fill out your copyright notice in the Description page of Project Settings.

#include "Matthiola.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

int32 AMyActor::DoSomeBranch2(int32 SomeInput, EMyEnum& Branches)
{
	if (SomeInput == 1)
	{
		Branches = EMyEnum::BranchA;
	}
	else
	{
		Branches = EMyEnum::BranchB;
	}
	return SomeInput;
}

void AMyActor::TestCallFunctionByName(FString str)
{
	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(*str, ar, NULL, true);
}

void AMyActor::DoSomeBranch(int32 SomeInput, EMyEnum& Branches)
{
	if (SomeInput == 1)
	{
		Branches = EMyEnum::BranchA;
	}
	else
	{
		Branches = EMyEnum::BranchB;
	}
}

