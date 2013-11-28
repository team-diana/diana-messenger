##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.0)
project(diana_messager)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC" )
##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs)
include_directories(${catkin_INCLUDE_DIRS})
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything.
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
catkin_package()

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically
# included via the dependency call in manifest.xml
#rosbuild_prepare_qt5(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/*.hpp)

#QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
#QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC} OPTIONS -DBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

# make all the linking static.
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

##############################################################################
# Sources
##############################################################################


file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)
file(GLOB diana_messager_srcs 
      "*.h"
          "*.cpp"
          )

set (srcs_list diana_factory diana_publisher listener publisher diana_listener
   generic_listener pantilt qnode)


 #foreach(fi ${srcs_list})
 #  message("generating moc for ${fi}.cpp)")
 #  qt5_generate_moc(${fi}.cpp ${fi}.moc)
 #  set( mocced_list ${mocced_list} ${fi}.moc)
 #endforeach(fi)
 #
 #message("Mocced list: ${mocced_list}")

##############################################################################
# Binaries
##############################################################################
include_directories(${headerDir} ${Qt5Core_INCLUDE_DIRS}  ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})


add_library(diana_messager SHARED ${diana_messager_srcs} ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(diana_messager ${QT_LIBRARIES} ${catkin_LIBRARIES})
qt5_use_modules(diana_messager Core Gui Widgets) 
install(TARGETS diana_messager LIBRARY DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})


add_subdirectory(test)
