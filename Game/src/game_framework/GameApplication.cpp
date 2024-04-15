#include "game_framework/GameApplication.h"
#include "config.h"

ly::Application *GetApplication() {
    return new ly::GameApplication{};
}


namespace ly {
    GameApplication::GameApplication()
            : Application{1280, 1024, "Game Engine", sf::Style::Titlebar | sf::Style::Close} {

        weak<World> newWorld = LoadWorld<World>();

        mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
        mActorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
        mActorToDestroy.lock()->SetActorLocation(sf::Vector2f(300, 200));
        mActorToDestroy.lock()->SetActorRotation(90.f);
    }

    void GameApplication::Tick(float deltaTime) {
        counter += deltaTime;
        if (counter > 2.f) {
            if (mActorToDestroy.expired()) {
                mActorToDestroy.lock()->Destroy();
            }
        }
    }


}
