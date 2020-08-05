// Troy Records Jr.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MenuInterface.h"

#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;

	void SetMenuInterface(IMenuInterface* InMenuInterface);

	void Setup();
	
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* ConnectButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;

	
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher = nullptr;
	UPROPERTY(meta = (BindWidget))
    class UWidget* JoinMenu = nullptr;
	UPROPERTY(meta = (BindWidget))
    class UWidget* MainMenu = nullptr;

private:
	UFUNCTION()
	void Host();
	UFUNCTION()
	void OpenJoinMenu();
	UFUNCTION()
	void GoBack();

	IMenuInterface* MenuInterface = nullptr;
};
