#include "framework/World.h"
#include "framework/Core.h"

namespace ly {

    World::World(Application *owningApp)
            : mOwningApp{owningApp},
              mBegunPlay{false},
              mActors{},
              mPendingActors{} {
    }

    World::~World() = default;

    void World::BeginPlayInternal() {
        if (!mBegunPlay) {
            mBegunPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime) {

        for (shared<Actor> actor: mPendingActors) {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }

        mPendingActors.clear();


        for (auto iter = mActors.begin(); iter != mActors.end();) {

            if(iter->get()->isPendingDestroy()) {
                iter = mActors.erase(iter);
            } else {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }

        }

        Tick(deltaTime);
    }

    void World::BeginPlay() {

    }

    void World::Tick(float deltaTime) {

        LOG("Tick at frame rate %f", 1.f / deltaTime);
    }

    void World::Render(sf::RenderWindow &window) {

        for(auto& actor : mActors){
            actor->Render(window);
        }
    }


}

