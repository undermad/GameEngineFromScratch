add_library(${GAME_ENGINE_FROM_SCRATCH} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
        src/framework/Core.cpp
        include/framework/Core.h
        src/framework/World.cpp
        include/framework/World.h
        src/framework/Actor.cpp
        include/framework/Actor.h
        src/framework/Object.cpp
        include/framework/Object.h
        src/framework/AssetManager.cpp
        include/framework/AssetManager.h
)

target_include_directories(${GAME_ENGINE_FROM_SCRATCH} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-graphics)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-window)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-system)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND
            ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibToTarget(sfml-graphics ${GAME_ENGINE_FROM_SCRATCH})
CopyLibToTarget(sfml-window ${GAME_ENGINE_FROM_SCRATCH})
CopyLibToTarget(sfml-system ${GAME_ENGINE_FROM_SCRATCH})
CopyLibToTarget(sfml-audio ${GAME_ENGINE_FROM_SCRATCH})



