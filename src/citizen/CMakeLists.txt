# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : citizen
# Brief   : Citizen entity system (static library)
# ==============================================================================

file(GLOB CITIZEN_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)
file(GLOB CITIZEN_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/include/*.h"
)

add_library(citizen STATIC
    ${CITIZEN_SOURCES}
    ${CITIZEN_HEADERS}
)

target_include_directories(citizen
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_link_libraries(citizen
    PRIVATE
        the_eye
)

source_group("Source Files" FILES ${CITIZEN_SOURCES})
source_group("Header Files" FILES ${CITIZEN_HEADERS})
