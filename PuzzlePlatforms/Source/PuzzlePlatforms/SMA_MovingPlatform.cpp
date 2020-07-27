// Troy Records Jr.


#include "SMA_MovingPlatform.h"

ASMA_MovingPlatform::ASMA_MovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SetMobility(EComponentMobility::Movable);
}

void ASMA_MovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    if(HasAuthority())    // Are we the server-client? (We are the one hosting the server)
    {
        SetReplicates(true);    // Means this is calculated on the server then send info to clients
        SetReplicateMovement(true); // Means this actors location is calculated on the server then send info to clients
    }
}

void ASMA_MovingPlatform::Tick(float DeltaSeconds)
{
    if(HasAuthority())
    {
        Super::Tick(DeltaSeconds);
        FVector Location = GetActorLocation();
        Location += FVector(MovementSpeed * DeltaSeconds,0,0);
        SetActorLocation(Location);
    }
    
}
