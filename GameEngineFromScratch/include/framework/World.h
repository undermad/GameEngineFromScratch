#pragma once

#include "Actor.h"
#include "Core.h"

namespace ly {

    class Actor;

    class Application;

    class World {

    public:
        World(Application* owningApp);
        virtual ~World();

        void BeginPlayInternal();
        void TickInternal(float deltaTime);
        void Render(sf::RenderWindow& window);

        sf::Vector2u GetWindowSize();

        template<typename ActorType>
        weak<ActorType> SpawnActor();


    private:
        Application* mOwningApp;
        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;

        void BeginPlay();
        void Tick(float deltaTime);
        bool mBegunPlay{};
    };


    template<typename ActorType>
    weak<ActorType> World::SpawnActor() {
        shared<ActorType> newActor{new ActorType{this}};
        mPendingActors.push_back(newActor);
        return newActor;
    }

}
