cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game src/main.cpp src/character.cpp headers/character.h src/wall.cpp headers/wall.h src/chest.cpp headers/chest.h src/game.cpp headers/game.h src/menu.cpp headers/menu.h src/target.cpp headers/target.h src/howtoplay.cpp headers/howtoplay.h src/end.cpp headers/end.h src/trophy.cpp headers/trophy.h)

include_directories(headers c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()




