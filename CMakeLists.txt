cmake_minimum_required(VERSION 2.8.0)
project(diana_messenger)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -std=c++11" )

find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs rostest)
include_directories(${catkin_INCLUDE_DIRS})

find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
catkin_package()

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/*.hpp)

QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC} OPTIONS -DBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)
file(GLOB diana_messenger_srcs
      "*.cpp"
    )


include_directories(${headerDir} ${Qt5Core_INCLUDE_DIRS}  ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})


add_library(diana_messenger SHARED ${diana_messenger_srcs} ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(diana_messenger ${QT_LIBRARIES} ${catkin_LIBRARIES})
qt5_use_modules(diana_messenger Core Gui Widgets)
install(TARGETS diana_messenger LIBRARY DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_rostest_gtest(diana_messenger_test test/test.test src/test/test.cpp)

target_link_libraries(diana_messenger_test diana_messenger)
