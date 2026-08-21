cmake_minimum_required(VERSION 3.16)

project(
    Calculadora
    VERSION 0.2.0
    LANGUAGES CXX    
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(
    Qt6 REQUIRED
    COMPONENTS Widgets
)

qt_standard_project_setup()

# Versão Console
add_executable(
    Calculadora
    main.cpp
    calculator.cpp
    console.cpp
)

# Versão Desktop
qt_add_executable(
    CalculadoraDesktop
    WIN32
    gui_main.cpp
    calculator.cpp
)

target_link_libraries(
    CalculadoraDesktop
    PRIVATE
    Qt6::Widgets   
)