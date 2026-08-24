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

# ==========================================
# DEPLOY AUTOMÁTICO DAS DLLs DO QT
# ==========================================

get_target_property(
    QT_QMAKE_EXECUTABLE
    Qt6::qmake
    IMPORTED_LOCATION
)

get_filename_component(
    QT_BIN_DIR
    "${QT_QMAKE_EXECUTABLE}"
    DIRECTORY
)

find_program(
    WINDEPLOYQT_EXECUTABLE
    windeployqt
    HINTS "${QT_BIN_DIR}"
)

add_custom_command(
    TARGET CalculadoraDesktop
    POST_BUILD

    COMMAND
        "${WINDEPLOYQT_EXECUTABLE}"
        "$<TARGET_FILE:CalculadoraDesktop>"

    COMMENT
        "Copiando dependencias do Qt..."
)