project(recipeApi VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Network)

file(GLOB Library_SOURCES "src/*.cpp")
file(GLOB Library_HEADER "include/*.h")

add_library(${PROJECT_NAME}
    ${Library_SOURCES}
    ${Library_HEADER}
    )

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Network
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    )

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    )
