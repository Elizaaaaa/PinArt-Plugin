// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PinArt.h"
#include "PinArtWindow.h"

#define LOCTEXT_NAMESPACE "PinArt"

const FName PinArtWindowTabName(TEXT("PinArtWindowTab"));

void FPinArtModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	TSharedPtr<FExtender> extender = MakeShareable(new FExtender);
	extender->AddMenuExtension("General", EExtensionHook::After, NULL,
		FMenuExtensionDelegate::CreateRaw(this, &FPinArtModule::CreateWindowMenu));

	FLevelEditorModule& levelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	levelEditor.GetMenuExtensibilityManager()->AddExtender(extender);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		PinArtWindowTabName,
		FOnSpawnTab::CreateRaw(this, &FPinArtModule::CreateTab)).SetDisplayName(FText::FromString(TEXT("Pin Art Window")));
}

void FPinArtModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FPinArtModule::CreateWindowMenu(FMenuBuilder& menuBuilder) {
	menuBuilder.AddMenuEntry(
		LOCTEXT("OpenWindow", "Pin Art"),
		LOCTEXT("OpenWindowTooltip", "Opens the Pin Art Plugin"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FPinArtModule::OpenPluginWindow))
	);
}

void FPinArtModule::OpenPluginWindow() {
	UE_LOG(LogTemp, Warning, TEXT("Hello from create window!"));

	FGlobalTabmanager::Get()->InvokeTab(PinArtWindowTabName);
}

TSharedRef<SDockTab> FPinArtModule::CreateTab(const FSpawnTabArgs& args) {
	return
		SNew(SDockTab)
		.Label(LOCTEXT("TabTitle", "Pin Art"))
		.TabRole(ETabRole::MajorTab)
		.ContentPadding(5)
		[
			SNew(SBorder)
			.Padding(4)
			.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
			[
				SNew(PinArtWindow)
			]
		];
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPinArtModule, PinArt)