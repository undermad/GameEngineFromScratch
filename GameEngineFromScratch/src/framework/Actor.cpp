#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {

    Actor::Actor(World *owningWorld)
        : owningWorld(owningWorld),
        mHasBeginPlay(false)
    {

    }

    Actor::~Actor() {
        LOG("Destroying Actor");
    }

    void Actor::BeginPlayInternal() {
        if(!mHasBeginPlay) {
            mHasBeginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay() {
        LOG("Actor began the game!");
    }

    void Actor::Tick(float deltaTime) {
        LOG("Actor is ticking");
    }



}
