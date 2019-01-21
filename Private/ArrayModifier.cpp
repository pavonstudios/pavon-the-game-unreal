// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SurvivalGame.h"
#include "ArrayModifier.h"


// Sets default values
AArrayModifier::AArrayModifier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    USceneComponent* new_scene_component = CreateDefaultSubobject<USceneComponent>(TEXT("ArrayMovable"));
    RootComponent = new_scene_component;
    
    
    
}

// Called when the game starts or when spawned
void AArrayModifier::BeginPlay()
{
	Super::BeginPlay();
    
    
    
	if(GetWorld()){
        TArray<ADuplicateInstance*> list_of_duplicate_instance;
        for(int i = 0; i<count ; i++){
            //GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Blue,TEXT("added a static mesh"));
            
            FVector location = GetActorLocation();  
            FRotator rotation = GetActorRotation();
            FVector location_of_last_element;
            FVector new_location;
            //location creation
            if(list_of_duplicate_instance.Num() > 0){
                location_of_last_element = list_of_duplicate_instance.Top()->GetActorLocation();
                FTransform local_transform = list_of_duplicate_instance.Top()->mesh->GetRelativeTransform();
               FVector local_position = local_transform.GetLocation();
               
               FVector final_local_location = FVector(0+offsetX,0,0);
               
             FVector final_world_location = final_local_location - list_of_duplicate_instance.Top()->GetActorLocation();
             
             FVector final_world_location2 = list_of_duplicate_instance.Top()->GetTransform().TransformPosition(final_local_location);
               //  FVector forward_direction = list_of_duplicate_instance.Top()->GetActorForwardVector();
                
                //FVector OffsetVector = forward_direction * 200;
                //new_location = FVector(location_of_last_element.X+200,location.Y,location.Z);
                
                new_location = final_world_location2;
            }else{
                new_location = location;
            }            
                       
            FActorSpawnParameters SpawnInfo;
            ADuplicateInstance *instance = GetWorld()->SpawnActor<ADuplicateInstance>( new_location,rotation,SpawnInfo);
            instance->mesh->SetStaticMesh(mesh_to_duplicate);
            list_of_duplicate_instance.Add(instance);
    }
    }
}

// Called every frame
void AArrayModifier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   

}

