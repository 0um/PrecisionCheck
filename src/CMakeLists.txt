cmake_minimum_required(VERSION 3.1.0)

add_custom_target(precision_check_run)
add_dependencies(precision_check_run matheval.qi matheval.x3)

project(precision_check)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)

set(SOURCE_ROOT "${CMAKE_SOURCE_DIR}/..")

add_subdirectory(
"${SOURCE_ROOT}/libs/boost_matheval/src/x3/"
${CMAKE_BINARY_DIR}/boost_matheval_x3
)

add_subdirectory(
"${SOURCE_ROOT}/libs/boost_matheval/src/qi/"
${CMAKE_BINARY_DIR}/boost_matheval_qi
)



add_executable(precision_check
    mainwindow.ui
    mainwindow.cpp
    main.cpp
    resources.qrc
)

target_link_libraries(precision_check PUBLIC Qt5::Widgets PRIVATE matheval::x3)
set_target_properties(precision_check PROPERTIES CXX_STANDARD 14)
set_source_files_properties(precision_check PROPERTIES COMPILE_FLAGS "/W1 /DNOMINMAX")

add_dependencies(precision_check_run precision_check)
