include_directories("${CMAKE_SOURCE_DIR}/inc" "${CMAKE_SOURCE_DIR}/src")

file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/inc/*.h" "${CMAKE_SOURCE_DIR}/src/*.cpp" "*.cpp")

list(REMOVE_ITEM TEST_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

if(BUILD_TESTING)
    add_executable(run_tests ${TEST_FILES})
    target_link_libraries(run_tests GTest::gtest_main GTest::gmock_main spdlog::spdlog)
    include(GoogleTest)
    gtest_discover_tests(run_tests)
endif()