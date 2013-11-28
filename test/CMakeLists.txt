project(ros_messager_test)
#FIND_PACKAGE(Qt5 REQUIRED)

#INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

add_executable(ros_messager_test main.cpp)

include_directories(../include)

target_link_libraries(ros_messager_test diana_messager ${QT_LIBRARIES})
