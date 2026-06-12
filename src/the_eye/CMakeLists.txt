# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : the_eye
# Brief   : Filesystem surveillance engine (static library)
# ==============================================================================

file(GLOB THE_EYE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

add_library(the_eye STATIC
    ${THE_EYE_SOURCES}
)

target_include_directories(the_eye
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

# Link yklib when you start using YkResult / YK_LOG_* in your code:
# target_link_libraries(the_eye PUBLIC yklib)

if(WIN32)
    target_link_libraries(the_eye
        PUBLIC
            kernel32
            user32
    )
endif()
