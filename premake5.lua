workspace "Hazel"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (Solution Directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"

include "Hazel/vendor/GLFW"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/Source/hzpch.cpp"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_BUILD_DLL",
			"HZ_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ..\\Binaries\\" .. outputdir .. "\\Sandbox"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "HZ_DISTRIBUTION"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"Hazel/Source",
		"Hazel/vendor/spdlog/include"
	}

	links
	{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "HZ_DISTRIBUTION"
		optimize "On"