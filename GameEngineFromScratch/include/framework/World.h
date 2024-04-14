#pragma once

#include "Actor.h"
#include "Core.h"

namespace ly {

    class Actor;

    class Application;

    class World {

    public:
        explicit World(Application *owningApp);

        void BeginPlayInternal();

        void TickInternal(float deltaTime);

        virtual ~World();

        template<typename ActorType>
        weak<ActorType> SpawnActor();

    private:
        void BeginPlay();

        void Tick(float deltaTime);

        Application *mOwningApp;
        bool mBegunPlay{};
        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };


    template<typename ActorType>
    weak<ActorType> World::SpawnActor() {
        shared<ActorType> newActor{new ActorType{this}};
        mPendingActors.push_back(newActor);
        return newActor;
    }

}
