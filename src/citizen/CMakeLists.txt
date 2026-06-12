# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : citizen
# Brief   : Citizen entity system (static library)
# ==============================================================================

file(GLOB CITIZEN_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

add_library(citizen STATIC
    ${CITIZEN_SOURCES}
)

target_include_directories(citizen
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)
