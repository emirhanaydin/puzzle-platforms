// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	void SetMenuInterface(IMenuInterface* MenuInterface);

protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel *Inlevel, UWorld *InWorld) override;

private:
	UPROPERTY(meta = (BindWidget))
		class UButton *ButtonMainHost;

	UPROPERTY(meta = (BindWidget))
		class UButton *ButtonMainJoin;

	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher *MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget *WidgetMainMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget *WidgetJoinMenu;

	UPROPERTY(meta = (BindWidget))
		class UButton *ButtonJoinBack;

	UFUNCTION()
		void OnClickedButtonMainHost();

	UFUNCTION()
		void OnClickedButtonMainJoin();

	UFUNCTION()
		void OnClickedButtonJoinBack();

	IMenuInterface *MenuInterface;
};
