# Windows
cmake_minimum_required(VERSION 3.16)
project(Physics_Engine)

set(CMAKE_CXX_STANDARD 20)

set(SFML_INCLUDE_DIR "C:/SFML/include")
set(SFML_LIB_DIR "C:/SFML/lib")


add_executable(Physics_Engine main.cpp
        GameObj.cpp
        GameObj.h
        Grid.cpp
        Grid.h
        Stone.cpp
        Stone.h
        Sand.cpp
        Sand.h
        Water.cpp
        Water.h
)

target_include_directories(Physics_Engine PRIVATE
        ${SFML_INCLUDE_DIR}
        headers
)

target_link_directories(Physics_Engine PRIVATE ${SFML_LIB_DIR})

# Link libraries (add -d for Debug builds)
target_link_libraries(Physics_Engine PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

#############################################################


## Linux
#cmake_minimum_required(VERSION 3.16)
#project(Physics_Engine)
#
#set(CMAKE_CXX_STANDARD 17)
#
#include_directories(/usr/local/include)
#link_directories(/usr/local/lib)
#
#add_executable(Physics_Engine main.cpp
#        GameObj.cpp
#        GameObj.h)
#
#target_link_libraries(Physics_Engine
#        sfml-graphics
#        sfml-window
#        sfml-system
#)
#############################################################
