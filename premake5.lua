workspace "particle-sim"
    toolset "clang"
    configurations {"Debug", "Release"}

project "particle-sim"
    kind "WindowedApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    links { "sfml-graphics", "sfml-window", "sfml-system" }

    files {"./src/**.hpp", "./src/**.cpp"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
