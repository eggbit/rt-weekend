workspace "baseline-c"
    configurations { "debug", "release" }
    architecture "universal"

    filter "configurations:debug"
        cdialect "C99"
        defines {
            "_DEBUG"
        }

    filter "configurations:release"
        cdialect "C99"
        optimize "Speed"

project "project"
    kind "ConsoleApp"
    language "C"
    
    files {
        "src/main.c"
    }
    
    includedirs {
        "src",
        "src/**",
    }
    
    buildoptions {
        "-Wall",
        "-Werror",
        "-Wextra",
        "-Wswitch-enum",
        "-g",
    }
    
    linkoptions {
    }