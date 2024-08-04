require "ninja"

workspace "Physics"
	configurations {"debug", "release" }
	architecture "x86_64"
	flags "MultiProcessorCompile"
	location "build"
	toolset "clang"

outputdir = "%{cfg.buildcfg}"

project "glfw"
	kind "StaticLib"
    systemversion "latest"
	language "C"
	staticruntime "off"
	warnings "off"

	targetdir ("build/bin/" .. outputdir)
    objdir ("build/bin-int/")

	files
	{
		"./vendor/glfw/include/GLFW/glfw3.h",
		"./vendor/glfw/include/GLFW/glfw3native.h",
		"./vendor/glfw/src/**.h",
        "./vendor/glfw/src/**.c"
	}

	defines 
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_GLFW_WIN32",
		"_NO_CRT_STDIO_INLINE"
	}

    links 
    {
        "gdi32"
    }
    
	filter "configurations:debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:release"
		runtime "Release"
		optimize "speed"

project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "off"

    targetdir ("build/bin/" .. outputdir)
    objdir ("build/bin-int/")

    files
    {
        "./vendor/glad/include/glad/gl.h",
        "./vendor/glad/include/KHR/khrplatform.h",
        "./vendor/glad/src/gl.c"
    }

    includedirs
    {
        "./vendor/glad/include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:release"
        runtime "Release"
        optimize "on"

project "spdlog"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	defines "SPDLOG_COMPILED_LIB"

	targetdir ("build/bin/" .. outputdir)
	objdir ("build/bin-int/")

	files
	{
		"vendor/spdlog/src/*.cpp",
		"vendor/spdlog/include",
		"vendor/spdlog/include/spdlog",
	}

	includedirs
	{
		"vendor/spdlog/include",
		"vendor/spdlog/include/spdlog",
	}

	filter "configurations:debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:release"
        runtime "Release"
        optimize "on"

project "Aether"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir("build/bin/" .. outputdir)
	objdir("build/bin-int")

	buildoptions {"-xc++", "-Wdeprecated-declarations", "-Wno-deprecated"}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"src",
		"vendor/glfw/include",
		"vendor/glad/include",
		"vendor/glm",
		"vendor/spdlog/include"
	}

	links
	{
		"glfw",
		"glad",
		"spdlog",
		"opengl32",
		"shell32",
		"user32",
		"gdi32"
	}

	filter "configurations:debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:release"
        runtime "Release"
        optimize "on"
		defines "AETHER_RELEASE"
