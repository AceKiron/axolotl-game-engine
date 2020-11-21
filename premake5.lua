workspace "Axolotl"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "Axolotl/vendor/spdlog/include"
IncludeDir["GLFW"] = "Axolotl/vendor/GLFW/include"

include "Axolotl/vendor/GLFW"

project "Axolotl"
	location "Axolotl"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "axpch.h"
	pchsource "Axolotl/src/axpch.cpp" -- Might need to change to Axolotl/src/axpch.cpp

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links { 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AX_PLATFORM_WINDOWS",
			"AX_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Axolotl/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links {
		"Axolotl"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AX_DIST"
		optimize "On"