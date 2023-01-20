cmake_minimum_required(VERSION 3.13)

include(FetchContent)

project(RecipeGUI VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)

set(PROJECT_SOURCES
    main.cpp
)

add_subdirectory(recipeApi)

qt_add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

qt_add_qml_module(${PROJECT_NAME}
    URI ${PROJECT_NAME}
    VERSION 1.0
    QML_FILES main.qml 
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Quick
    recipeApi
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.{PROJECT_VERSION_PATCH}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

enable_testing()

add_subdirectory(Test)

FetchContent_Declare(GoogleTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(GoogleTest)
