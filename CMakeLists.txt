cmake_minimum_required(VERSION 3.1.0)

project("QtJsonExample"
        VERSION 1.0.0
        DESCRIPTION "QtJsonExample")

set(${PROJECT_NAME}_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(${PROJECT_NAME}_CONFIG_DIR "${CMAKE_SOURCE_DIR}/cmake")

include(${${PROJECT_NAME}_CONFIG_DIR}/CompilerOptions.cmake)

set(${PROJECT_NAME}_EXECUTABLE_NAME ${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_CODE
    ${${PROJECT_NAME}_SOURCE_DIR}/DataType/Ball/Ball.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/DataType/Ball/Ball.h
    ${${PROJECT_NAME}_SOURCE_DIR}/DataType/Box/Box.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/DataType/Box/Box.h
    ${${PROJECT_NAME}_SOURCE_DIR}/Jsonable/JsonReadable.h
    ${${PROJECT_NAME}_SOURCE_DIR}/Jsonable/JsonReadWriteable.h
    ${${PROJECT_NAME}_SOURCE_DIR}/Jsonable/JsonWriteable.h
    ${${PROJECT_NAME}_SOURCE_DIR}/Main.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/Randomizer/Randomizer.h
    ${${PROJECT_NAME}_SOURCE_DIR}/Randomizer/Randomizer.cpp
)

find_package(Qt5
    COMPONENTS
        Core
        Gui
        Widgets
    REQUIRED
)

add_executable(${${PROJECT_NAME}_EXECUTABLE_NAME}
    ${${PROJECT_NAME}_SOURCE_CODE}
)

set_target_properties(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
)

target_include_directories(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        ${${PROJECT_NAME}_SOURCE_DIR}
)

target_compile_features(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        cxx_std_11
)

target_compile_options(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        "$<$<CONFIG:DEBUG>:${${PROJECT_NAME}_CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:RELEASE>:${${PROJECT_NAME}_CXX_FLAGS_RELEASE}>"
)

target_link_libraries(${${PROJECT_NAME}_EXECUTABLE_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

include(${${PROJECT_NAME}_CONFIG_DIR}/PostBuildCommand.cmake)
