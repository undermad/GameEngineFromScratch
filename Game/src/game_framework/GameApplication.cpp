#include "game_framework/GameApplication.h"
#include "config.h"

ly::Application *GetApplication() {
    return new ly::GameApplication{};
}


namespace ly {
    GameApplication::GameApplication()
        : Application{1280, 1024, "Game Engine", sf::Style::Titlebar | sf::Style::Close}
    {

        weak<World> newWorld = LoadWorld<World>();
        weak<Actor> actorToSpawn = newWorld.lock()->SpawnActor<Actor>();

        mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
        mActorToDestroy.lock()->setTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
        counter = 0;
    }

    void GameApplication::Tick(float deltaTime) {
        counter += deltaTime;
        if(counter > 2.f) {
            if(mActorToDestroy.expired()) {
                mActorToDestroy.lock()->Destroy();
            }
        }
    }


}
