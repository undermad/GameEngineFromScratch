#include "game_framework/GameApplication.h"

ly::Application *GetApplication() {
    return new ly::GameApplication{};
}


namespace ly {
    GameApplication::GameApplication() {

        weak<World> newWorld =  LoadWorld<World>();

        weak<Actor> actorToSpawn = newWorld.lock()->SpawnActor<Actor>();
        actorToDestroy = newWorld.lock()->SpawnActor<Actor>();

    }


}
