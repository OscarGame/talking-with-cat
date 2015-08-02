// Fill out your copyright notice in the Description page of Project Settings.

#include "AVGPrivatePCH.h"
#include "FightCharacter.h"
#include "PaperFlipbookComponent.h"
// for GEngine
#include "Engine.h"

FName AFightCharacter::SpriteComponentName(TEXT("Sprite0"));

AFightCharacter::AFightCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	// Try to create the sprite component
	Sprite = ObjectInitializer.CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(this, APaperCharacter::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->AttachParent = GetCapsuleComponent();
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->bGenerateOverlapEvents = false;
	}
}

void AFightCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!IsPendingKill())
	{
		if (Sprite)
		{
			// force animation tick after movement component updates
			if (Sprite->PrimaryComponentTick.bCanEverTick && GetCharacterMovement())
			{
				Sprite->PrimaryComponentTick.AddPrerequisite(GetCharacterMovement(), GetCharacterMovement()->PrimaryComponentTick);
			}
		}
	}
}

void AFightCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	bool needattack = false;
	// for loop all AFightCharacter
	for (TActorIterator<AFightCharacter> It(GetWorld()); It; ++It)
	{
		// if different Faction with our
		if (It->Faction != this->Faction)
		{
			// attack
			if (FVector::Dist(It->GetActorLocation(), this->GetActorLocation()) < AttackRadius)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, this->GetName() + TEXT(" attack"));
				Sprite->SetFlipbook(PF_Attacking1);
				this->GetController()->StopMovement();
				needattack = true;
				break;
			}
		}
	}
	if (!needattack)
	{
		//UNavigationSystem::SimpleMoveToLocation(this->GetController(), Destination);
	}
	// if no attack go to Destination
	
}

void AFightCharacter::SetDestination(FVector dst)
{
	Destination = dst;
}
