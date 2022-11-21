cmake_minimum_required(VERSION 3.22)
project(QuarantineInfectedII)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

    add_executable(QuarantineInfectedII src/main.cpp src/gui/HelloWorld.cpp src/graph/Graph.cpp src/plane2D/Plane2D.cpp src/engine/Engine.cpp)
target_link_libraries(QuarantineInfectedII
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

