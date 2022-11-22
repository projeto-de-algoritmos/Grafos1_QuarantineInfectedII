cmake_minimum_required(VERSION 3.22)
project(QuarantineInfectedII)

set(CMAKE_CXX_STANDARD 14)

    add_executable(QuarantineInfectedII src/main.cpp src/graph/Graph.cpp src/plane2D/Plane2D.cpp src/engine/Engine.cpp)
target_link_libraries(QuarantineInfectedII
        )

