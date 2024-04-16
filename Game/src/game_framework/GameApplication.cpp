#include "game_framework/GameApplication.h"
#include "config.h"
#include "framework/AssetManager.h."

ly::Application *GetApplication() {
    return new ly::GameApplication{};
}


namespace ly {
    GameApplication::GameApplication()
            : Application{1280, 1024, "Game Engine", sf::Style::Titlebar | sf::Style::Close} {

        AssetManager::GetInstance().SetAssetRootDir(GetResourceDir());
        weak<World> newWorld = LoadWorld<World>();

        testPlayer = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayer.lock()->SetActorLocation(sf::Vector2f(500, 500));

        weak<Spaceship> testCollisionSpaceship = newWorld.lock()->SpawnActor<Spaceship>();
        testCollisionSpaceship.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
        testCollisionSpaceship.lock()->SetActorLocation(sf::Vector2f(100,100));

 }

    void GameApplication::Tick(float deltaTime) {

    }


}
