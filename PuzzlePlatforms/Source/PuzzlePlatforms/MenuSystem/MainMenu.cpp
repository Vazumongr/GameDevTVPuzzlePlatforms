// Troy Records Jr.


#include "MainMenu.h"


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

void UMainMenu::SetMenuInterface(IMenuInterface* InMenuInterface)
{
    MenuInterface = InMenuInterface;
}

void UMainMenu::Host()
{
    if(!ensure(MenuInterface)) return;
    MenuInterface->Host();
    
    UE_LOG(LogTemp, Warning, TEXT("Hosting..."));
}

void UMainMenu::Join()
{
    UE_LOG(LogTemp, Warning, TEXT("I am joining..."));
}
