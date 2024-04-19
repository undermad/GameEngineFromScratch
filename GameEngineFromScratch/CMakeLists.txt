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
        src/framework/MathUtility.cpp
        include/framework/MathUtility.h
        src/framework/Physics.cpp
        include/framework/Physics.h
        src/framework/Delegate.cpp
        include/framework/Delegate.h
        src/VFX/Particle.cpp
        include/VFX/Particle.h
)

target_include_directories(${GAME_ENGINE_FROM_SCRATCH} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
set(SFML_LIB_NAME    SFML)

FetchContent_Declare(
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 2.5.1
        GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-graphics)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-window)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-system)
target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC sfml-audio)



set(BOX2D_LIB_NAME Box2d)

FetchContent_Declare(
        ${BOX2D_LIB_NAME}
        GIT_REPOSITORY https://github.com/erincatto/box2d
        GIT_TAG v2.4.1
        GIT_SHALLOW FALSE
)
FetchContent_MakeAvailable(${BOX2D_LIB_NAME})

target_link_libraries(${GAME_ENGINE_FROM_SCRATCH} PUBLIC box2d)


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
CopyLibToTarget(box2d ${GAME_ENGINE_FROM_SCRATCH})



