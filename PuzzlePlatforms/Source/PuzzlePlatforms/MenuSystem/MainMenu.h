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
	

protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton = nullptr;

private:
	UFUNCTION()
	void Host();
	UFUNCTION()
	void Join();

	IMenuInterface* MenuInterface = nullptr;
};
