# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : root
# Brief   : FilesRPG — Filesystem Simulation Engine
# ==============================================================================

cmake_minimum_required(VERSION 3.20)

project(FilesRPG
    VERSION     0.0.0
    LANGUAGES   C
    DESCRIPTION "FilesRPG — Filesystem Simulation Engine"
)

# -- Standards -----------------------------------------------------------------
set(CMAKE_C_STANDARD          11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS        OFF)

# -- Output directories --------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# -- Global compile options ----------------------------------------------------
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Werror
        -Wimplicit-function-declaration
        -Wstrict-prototypes
        -Wmissing-prototypes
    )
endif()

# -- Win32 global defines -----------------------------------------------------
if(WIN32)
    add_compile_definitions(
        _WIN32_WINNT=0x0A00   # Windows 10+
        WINVER=0x0A00
        WIN32_LEAN_AND_MEAN   # Strip rarely used Win32 headers
        UNICODE               # Force W variants (CreateFileW not CreateFileA)
        _UNICODE
        NOMINMAX              # Prevent Win32 min/max macro pollution
    )
endif()

# -- yklib (Git submodule — uncomment when you start using it) -----------------
# add_subdirectory(extern/yklib)

# -- Project modules -----------------------------------------------------------
add_subdirectory(src/the_eye)
add_subdirectory(src/citizen)
add_subdirectory(apps/game_launcher)
# add_subdirectory(tests)  # Uncomment when you add test files

# -- Docs (optional) -----------------------------------------------------------
find_package(Doxygen OPTIONAL_COMPONENTS dot)
if(DOXYGEN_FOUND)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        @ONLY
    )
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating documentation..."
        VERBATIM
    )
endif()
