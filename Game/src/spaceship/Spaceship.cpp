#include "spaceship/Spaceship.h"


namespace ly {


    Spaceship::Spaceship(World *owningWorld, const std::string &texturePath)
            : Actor(owningWorld, texturePath) {

    }

    void Spaceship::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(GetVelocity() * deltaTime);

    }

    void Spaceship::SetVelocity(const sf::Vector2f &newVelocity) {
        mVelocity = newVelocity;
    }

}