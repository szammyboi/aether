require "ninja"

workspace "Physics"
	configurations {"release", "debug"}
	architecture "x86_64"
	flags "MultiProcessorCompile"
	toolset "clang"

outputdir = "%{cfg.buildcfg}"

project "Aether"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir("build/bin/" .. outputdir)
	objdir("build/bin-int")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

