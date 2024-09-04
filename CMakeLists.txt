cmake_minimum_required(VERSION 3.28)

project(cpp
    DESCRIPTION "C++20 with modules, clang++ and ninja"
    LANGUAGES CXX
)
set(PROJECT_VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

# External libraries in the 'ext' folder

# available only at build time with FetchContent: (good for pipelines)
#
# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
# )
# FetchContent_MakeAvailable(googletest)

# already downloaded and locally installed: (good for local development)
#
find_package(Boost
    1.86.0 EXACT REQUIRED
    CONFIG
    PATHS ${CMAKE_SOURCE_DIR}/ext/boost_1_86_0/lib/cmake
    COMPONENTS
        date_time
)

find_package(GTest
    1.15.2 EXACT REQUIRED
    CONFIG
    PATHS ${CMAKE_SOURCE_DIR}/ext/googletest-1.15.2/lib/cmake
)


# Modules
macro(add_module MODULE_NAME)
    set(MODULES_PATH "src/module")
    file(GLOB MODULE_${MODULE_NAME}_IXX "${MODULES_PATH}/${MODULE_NAME}/*.ixx")
    file(GLOB MODULE_${MODULE_NAME}_SRC "${MODULES_PATH}/${MODULE_NAME}/src/*.cpp")
    file(GLOB MODULE_${MODULE_NAME}_TST "${MODULES_PATH}/${MODULE_NAME}/test/*.cpp")

    add_library(${MODULE_NAME})
    target_sources(${MODULE_NAME}
        PUBLIC
            FILE_SET CXX_MODULES
            FILES
                ${MODULE_${MODULE_NAME}_IXX}
        PRIVATE
            ${MODULE_${MODULE_NAME}_SRC}
    )

    add_executable(${MODULE_NAME}_test)
    target_sources(${MODULE_NAME}_test
        PUBLIC
            FILE_SET CXX_MODULES
            FILES
                ${MODULE_${MODULE_NAME}_IXX}
        PRIVATE
            ${MODULE_${MODULE_NAME}_SRC}
            ${MODULE_${MODULE_NAME}_TST}
    )
    target_link_libraries(${MODULE_NAME}_test GTest::gtest_main)
    add_test("module ${MODULE_NAME}" ${MODULE_NAME}_test)
endmacro()

# for each module:
add_module(hello)


# Main Sources & Executables
file(GLOB SOURCES "src/*.?pp")
add_executable(main ${SOURCES})

# add libraries to executables
target_link_libraries(main hello Boost::date_time)