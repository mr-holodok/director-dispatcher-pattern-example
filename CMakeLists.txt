cmake_minimum_required(VERSION 3.15.2)

project(simple-red-tracker LANGUAGES CXX)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(simple-red-tracker src/main.cpp
                                  src/video_provider.cpp
                                  src/image_analyzer.cpp
                                  src/image_analysis_strategy_selector.cpp
                                  src/event_manager.cpp
                                  src/detector.cpp
                                  src/tracker.cpp
                                  src/notifier.cpp)
target_include_directories(simple-red-tracker PRIVATE include)
target_link_libraries(simple-red-tracker PRIVATE ${OpenCV_LIBS})
