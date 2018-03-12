// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "LevelEditor.h"
#include "LevelEditorActions.h"
#include "SharedPointer.h"
#include "Internationalization.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MultiBoxExtender.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "EngineUtils.h"
#include "Builders/CylinderBuilder.h"
#include "UObject.h"
#include "GameFramework/Actor.h"

class FPinArtModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void CreateWindowMenu(FMenuBuilder& menuBuilder);
	void OpenPluginWindow();
	TSharedRef<SDockTab> CreateTab(const FSpawnTabArgs& args);
};