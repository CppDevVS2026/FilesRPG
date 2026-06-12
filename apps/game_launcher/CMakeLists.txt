# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : game_launcher
# Brief   : Main executable — FilesRPG entry point
# ==============================================================================

file(GLOB LAUNCHER_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

add_executable(game_launcher
        ${LAUNCHER_SOURCES}
)

target_include_directories(game_launcher
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include

)

# Link modules as you build them:
target_link_libraries(game_launcher PRIVATE the_eye)

set_target_properties(game_launcher PROPERTIES
        OUTPUT_NAME "FilesRPG"
)
