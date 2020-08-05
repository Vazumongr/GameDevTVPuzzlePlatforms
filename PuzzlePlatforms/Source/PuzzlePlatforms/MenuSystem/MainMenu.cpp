// Troy Records Jr.


#include "MainMenu.h"
#include "Components/WidgetSwitcher.h"
#include "Components/VerticalBox.h"


bool UMainMenu::Initialize()
{
    bool Success = Super::Initialize();
    
    if(!Success) return false;

    if(!ensure(HostButton)) return false;
    HostButton->OnClicked.AddDynamic(this, &UMainMenu::Host);

    if(!ensure(JoinButton)) return false;
    JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
    
    if(!ensure(BackButton)) return false;
    BackButton->OnClicked.AddDynamic(this, &UMainMenu::GoBack);

    return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* InMenuInterface)
{
    MenuInterface = InMenuInterface;
}

void UMainMenu::Setup()
{
    this->AddToViewport();
    this->bIsFocusable = true;
    
    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(this->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    UWorld* World = GetWorld();
    if(!ensure(World)) return;
    
    APlayerController* PlayerController = World->GetFirstPlayerController();
    if(!ensure(PlayerController)) return;
    
    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
    FInputModeGameOnly InputModeData;
    InputModeData.SetConsumeCaptureMouseDown(false);

    if(!ensure(InWorld)) return;
    
    APlayerController* PlayerController = InWorld->GetFirstPlayerController();
    if(!ensure(PlayerController)) return;
    
    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = false;
    
    this->RemoveFromViewport();
}

void UMainMenu::Host()
{
    if(!ensure(MenuInterface)) return;
    MenuInterface->Host();
    
    UE_LOG(LogTemp, Warning, TEXT("Hosting..."));
}

void UMainMenu::OpenJoinMenu()
{
    if(ensure(JoinMenu) && ensure(MenuSwitcher))
    {
        MenuSwitcher->SetActiveWidget(JoinMenu);
    }
        
}

void UMainMenu::GoBack()
{
    if(ensure(MainMenu) && ensure(MenuSwitcher))
    {
        MenuSwitcher->SetActiveWidget(MainMenu);
    }
}
