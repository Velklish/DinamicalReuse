cmake_minimum_required(VERSION 3.1.0)

project(DynamicalReuse)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

set(DynamicalReuse_SRCS
	base_items.cpp
	listmodel_delegate.cpp
    list_model.cpp
    main_window.cpp
    main.cpp
)
set(DynamicalReuse_HDRS
	main_window.h
	list_model.h
	base_items.h
	listmodel_delegate.h
)


add_executable(DynamicalReuse WIN32 ${DynamicalReuse_SRCS} ${DynamicalReuse_HDRS})
target_link_libraries(DynamicalReuse Qt5::Widgets)

get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET DynamicalReuse POST_BUILD
       COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:DynamicalReuse>)