cmake_minimum_required(VERSION 3.1.0)

project(DynamicalReuse)

set(CMAKE_PREFIX_PATH "E:/Qt/5.12.3/msvc2017_64/lib/cmake/Qt5")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

set(DynamicalReuse_SRCS
    list_model.h
    list_model.cpp
    main.cpp
)
set(DynamicalReuse_HDRS
	list_model.h
)


add_executable(DynamicalReuse WIN32 ${DynamicalReuse_SRCS} ${DynamicalReuse_HDRS})
target_link_libraries(DynamicalReuse Qt5::Widgets)

add_custom_command(TARGET DynamicalReuse PRE_BUILD
COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Cored.dll         ${CMAKE_BINARY_DIR})

add_custom_command(TARGET DynamicalReuse PRE_BUILD
COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Widgetsd.dll      ${CMAKE_BINARY_DIR})

add_custom_command(TARGET DynamicalReuse PRE_BUILD
COMMAND ${CMAKE_COMMAND} -E copy ${Qt5Core_DIR}/../../../bin/Qt5Guid.dll          ${CMAKE_BINARY_DIR})