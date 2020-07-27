// Troy Records Jr.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SMA_MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API ASMA_MovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ASMA_MovingPlatform();

	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnywhere);
	float MovementSpeed = 5.0f;
	
};
