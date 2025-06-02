// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EscapeHouse : ModuleRules
{
	public EscapeHouse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PublicIncludePaths.AddRange(new string[] {
			"EscapeHouse/killer"
		});
	}
}
