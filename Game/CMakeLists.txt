add_executable(${GAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/game_framework/GameApplication.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/game_framework/GameApplication.cpp
)

target_include_directories(${GAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GAME} PUBLIC ${GAME_ENGINE_FROM_SCRATCH})


function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND
            ${CMAKE_COMMAND} -E copy_directory
            $<TARGET_FILE_DIR:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirToTarget(${GAME_ENGINE_FROM_SCRATCH} ${GAME})




