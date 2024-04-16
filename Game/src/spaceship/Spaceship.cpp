#include "spaceship/Spaceship.h"
#include "framework/MathUtility.h"
#include <cmath>


namespace ly {


    Spaceship::Spaceship(World *owningWorld, const std::string &texturePath)
            : Actor(owningWorld, texturePath) {

    }

    void Spaceship::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(mAccelerationVelocity * deltaTime);
        AddActorRotationOffest(mRotationVelocity * deltaTime);
    }

    void Spaceship::SetVelocity(const sf::Vector2f &newVelocity) {
        mVelocity = newVelocity;
    }

    void Spaceship::SetRotationVelocity(float newVelocity) {
        mRotationVelocity = newVelocity;
    }

    void Spaceship::SetAccelerationVelocity(const sf::Vector2f& newVelocity) {
        mAccelerationVelocity = newVelocity;
    }

    void Spaceship::Shoot() {

    }

    void Spaceship::BeginPlay() {
        Actor::BeginPlay();

        SetEnablePhysics(true);
    }


}