#pragma once


#include "Object.h"

namespace ly {

    class World;

    class Actor : public Object {

    public:
        explicit Actor(World *owningWorld);

        ~Actor();

        void BeginPlayInternal();

        virtual void BeginPlay();

        virtual void Tick(float deltaTime);

    private:
        World *owningWorld;
        bool mHasBeginPlay;


    };

}

