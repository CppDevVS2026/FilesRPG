# ==============================================================================
# Yokim Gold Standard v4.0
# Module  : tests
# Brief   : Unity-style test suite
# ==============================================================================

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

if(TEST_SOURCES)
    add_executable(run_tests
        ${TEST_SOURCES}
    )

    target_link_libraries(run_tests
        PRIVATE
            the_eye
            citizen
            yklib
    )

    target_include_directories(run_tests
        PRIVATE
            ${CMAKE_SOURCE_DIR}/include
    )

    enable_testing()
    add_test(
        NAME    FilesRPGTests
        COMMAND run_tests
    )

    set_tests_properties(FilesRPGTests PROPERTIES
        ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1"
    )
endif()
