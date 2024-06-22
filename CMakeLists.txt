﻿# CMakeList.txt : CMake project for GamersAgainstWeedWebsiteCPlusPlus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Add source to this project's executable.
add_executable (GamersAgainstWeedWebsiteCPlusPlus "main.cpp" "Server.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GamersAgainstWeedWebsiteCPlusPlus PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

find_package(cxxopts CONFIG REQUIRED)
target_link_libraries(GamersAgainstWeedWebsiteCPlusPlus PRIVATE cxxopts::cxxopts)


find_package(xsimd CONFIG REQUIRED)
target_link_libraries(GamersAgainstWeedWebsiteCPlusPlus PRIVATE xsimd)