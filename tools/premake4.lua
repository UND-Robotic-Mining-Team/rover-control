#!lua

solution "rover-control"
   configurations { "Debug", "Release" }

   files {
      "../src/*.cpp",
      "../include/*.h"
   }

   includedirs {
      "../include"
   }

   project "rover-control"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "**.cpp" }

      configuration "Debug"
         defines { "DEBUG" }
         flags { "Symbols" }
         targetdir "../build/Debug"

      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }
         targetdir "../build/Release"
