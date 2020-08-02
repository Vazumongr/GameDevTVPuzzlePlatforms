// Troy Records Jr.


#include "MainMenu.h"

#include "PuzzlePlatforms/PuzzlePlatformsGameInstance.h"


bool UMainMenu::Initialize()
{
    bool Success = Super::Initialize();
    
    if(!Success) return false;

    if(!ensure(HostButton)) return false;
    HostButton->OnClicked.AddDynamic(this, &UMainMenu::Host);

    if(!ensure(JoinButton)) return false;
    JoinButton->OnClicked.AddDynamic(this, &UMainMenu::Join);

    return true;
}

void UMainMenu::Host()
{
    UE_LOG(LogTemp, Warning, TEXT("Hosting..."));
    
    UPuzzlePlatformsGameInstance* GameInstance = Cast<UPuzzlePlatformsGameInstance>(GetGameInstance());
    if(!ensure(GameInstance)) return;
    GameInstance->Host();
}

void UMainMenu::Join()
{
    UE_LOG(LogTemp, Warning, TEXT("I am joining..."));
}
