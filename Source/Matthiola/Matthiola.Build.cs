// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Matthiola : ModuleRules
{
	public Matthiola(TargetInfo Target)
	{
        PublicDependencyModuleNames.AddRange(new string[] { 
        "Core", 
        "CoreUObject", 
        "Engine", 
        "InputCore", 
        "Paper2D",
        "AVG",
        "MoviePlayer",
        "UMG", 
        "Slate",
        "SlateCore", 
        "ScriptPlugin"
		});
        if (UEBuildConfiguration.bBuildEditor)
        {
            PublicDependencyModuleNames.AddRange(new string[] {"AVGEditor", "ScriptEditorPlugin"});
        }
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
