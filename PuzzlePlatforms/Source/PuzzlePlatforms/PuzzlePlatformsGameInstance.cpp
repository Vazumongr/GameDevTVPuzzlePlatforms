// Troy Records Jr.


#include "PuzzlePlatformsGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("Constructed"));
    ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetBP(TEXT("/Game/MenuSystem/WBP_MainMenu"));
    if(!ensure(MainMenuWidgetBP.Class)) return;
    MainMenuWidgetClass = MainMenuWidgetBP.Class;
    
}

void UPuzzlePlatformsGameInstance::Init()
{
    if(ensure(MainMenuWidgetClass))
        UE_LOG(LogTemp, Warning, TEXT("Found class: %s"), *MainMenuWidgetClass->GetName());
}

void UPuzzlePlatformsGameInstance::Host()
{   
    UEngine* Engine = GetEngine();
    if(!ensure(Engine != nullptr)) return;
    
    Engine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("Hosting..."));

    UWorld* World = GetWorld();
    if(!ensure(World != nullptr)) return;

    World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, FString::Printf(TEXT("Joining %s"), *Address));

    APlayerController* PlayerController = GetFirstLocalPlayerController();
    if(!ensure(PlayerController)) return;

    PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
    
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
    if(!ensure(MainMenuWidgetClass)) return;
    MainMenuWidget = CreateWidget<UMainMenu>(this, MainMenuWidgetClass);
        
    if(!ensure(MainMenuWidget)) return;

    MainMenuWidget->Setup();
    
    MainMenuWidget->SetMenuInterface(this);
}
