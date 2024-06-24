# CMakeList.txt : CMake project for GamersAgainstWeedWebsiteCPlusPlus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
project(GamersAgainstWeedWebsite)

# Add source to this project's executable.
add_executable (GamersAgainstWeedWebsiteCPlusPlus "src/main.cpp" "src/Server/Server.hpp" "src/Server/Common.hpp" "src/Server/Common.cxx" "src/Server/Server.cxx")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GamersAgainstWeedWebsiteCPlusPlus PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(cxxopts CONFIG REQUIRED)
target_link_libraries(GamersAgainstWeedWebsiteCPlusPlus PRIVATE cxxopts::cxxopts)


find_package(xsimd CONFIG REQUIRED)
target_link_libraries(GamersAgainstWeedWebsiteCPlusPlus PRIVATE xsimd)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS filesystem iostreams REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif ()

# ...
target_link_libraries(GamersAgainstWeedWebsiteCPlusPlus PRIVATE Boost::boost)
#Some build macros 
target_compile_definitions(GamersAgainstWeedWebsiteCPlusPlus
    PRIVATE
        # If the debug configuration pass the DEBUG define to the compiler 
        $<$<CONFIG:Debug>:DEBUG>
)
