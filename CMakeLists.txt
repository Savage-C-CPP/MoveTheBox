#========== Settings ==========#
cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME MoveTheBox)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

#========== target: MoveTheBox ==========#
# folder/** allows to include files directly by filename, not like "subdir/filename.hpp"
file(GLOB_RECURSE SOURCE_FILES sources/**)
file(GLOB_RECURSE SOURCE_HEADERS include/**)
set(SOURCES ${SOURCE_FILES} ${SOURCE_HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_include_directories(${PROJECT_NAME} PRIVATE include/Game)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

#========== target: GTest ==========#
# Do not touch while it work correct
# 'GTest' is the folder with Google Test sources
set(TESTS_NAME Google_Tests)
add_subdirectory(GTest)

# 'tests/*' is the folder with tests source files
file(GLOB_RECURSE TESTS_FILES tests/*)
set(TESTS ${TESTS_FILES})

file(GLOB_RECURSE TEST_ME_SOURCES sources/Game/**)
file(GLOB_RECURSE TEST_ME_HEADERS include/Game/**)
set(TEST_ME ${TEST_ME_SOURCES} ${TEST_ME_HEADERS} )

add_executable(${TESTS_NAME} ${TEST_ME} ${TESTS})

target_include_directories(${TESTS_NAME} PRIVATE include/Game)
target_include_directories(${TESTS_NAME} PRIVATE ${gtest_SOURCE_DIR})
target_include_directories(${TESTS_NAME} PRIVATE ${gtest_SOURCE_DIR}/include)

target_link_libraries(${TESTS_NAME} gtest gtest_main)
