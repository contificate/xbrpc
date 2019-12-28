cmake_minimum_required(VERSION 3.5)

project(xbrpc LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS res/ui)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(xbrpc
  src/main.cc
  src/ui/main_window.cc
  include/ui/main_window.h
  res/ui/main_window.ui
  src/ui/call_pane.cc
  include/ui/call_pane.h
  res/ui/call_pane.ui

  src/ui/param_delegate.cc
  include/ui/param_delegate.h

  res/icons/icons.qrc
)

include_directories(include/)

target_link_libraries(xbrpc PRIVATE Qt5::Widgets)
