if (WIN32)
    set(COPYABLES
        $<TARGET_FILE:Qt5::Core>
        $<TARGET_FILE:Qt5::Gui>
        $<TARGET_FILE:Qt5::Widgets>
    )
endif()

foreach(COPYABLE ${COPYABLES})
    add_custom_command(
        TARGET ${${PROJECT_NAME}_EXECUTABLE_NAME} POST_BUILD
        COMMAND
            ${CMAKE_COMMAND} -E copy_if_different
            ${COPYABLE}
            $<TARGET_FILE_DIR:${${PROJECT_NAME}_EXECUTABLE_NAME}>
    )
endforeach()
