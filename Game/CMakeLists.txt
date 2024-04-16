add_executable(${GAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/game_framework/GameApplication.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/game_framework/GameApplication.cpp
        src/spaceship/Spaceship.cpp
        include/spaceship/Spaceship.h
        src/player/PlayerSpaceship.cpp
        include/player/PlayerSpaceship.h
        src/weapon/Shooter.cpp
        include/weapon/Shooter.h
        src/weapon/BulletShooter.cpp
        include/weapon/BulletShooter.h
        src/weapon/Bullet.cpp
        include/weapon/Bullet.h
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

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME})

add_custom_command(TARGET ${GAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCE_SRC_DIR}
        $<TARGET_FILE_DIR:${GAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
        "config.h.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)



