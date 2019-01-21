// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SimpleCar.generated.h"

UCLASS()
class SURVIVALGAME_API ASimpleCar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASimpleCar();
    
    UPROPERTY(EditAnywhere)
    USceneComponent* OurVisibleComponent;
 
    virtual void MoveForward(float Val);

	virtual void MoveRight(float Val);
    
    /** Movement component used for movement logic in various movement modes (walking, falling, etc), containing relevant settings and functions to control movement. */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UCharacterMovementComponent* CharacterMovement;
    
    /** Returns CharacterMovement subobject **/
	FORCEINLINE class UCharacterMovementComponent* GetCharacterMovement() const { return CharacterMovement; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void EnterInCar();
	
};
