cmake_minimum_required(VERSION 3.22.1)
project(Farming_on_Brazil C CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(Farming_on_Brazil 
                src/main.cpp 
                src/classes/character/char.cpp
                src/classes/itens/Items.cpp
                src/classes/inventario/inventario.cpp
                src/classes/itens/tangerina.cpp
                src/classes/itens/maracuja.cpp
                src/classes/terreno/solo.cpp
                src/classes/terreno/terreno.cpp     
                )
target_link_libraries(Farming_on_Brazil PRIVATE raylib)
target_include_directories(Farming_on_Brazil PRIVATE src)

# Copia a pasta assets pra perto do executavel (o jogo procura "assets/..." na pasta do executavel)
add_custom_command(TARGET Farming_on_Brazil POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Farming_on_Brazil>/assets
)
