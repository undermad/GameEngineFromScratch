#pragma once


#include "framework/Actor.h"

namespace ly {

    class Spaceship : public Actor {
    public:
        Spaceship(World *owningWorld, const std::string &texturePath = "");

        void Tick(float deltaTime) override;

        void SetVelocity(const sf::Vector2f &newVelocity);

        sf::Vector2f GetVelocity() const { return mVelocity; };

        float GetRotationVelocity() const { return mRotationVelocity; };

        void SetRotationVelocity(float newVelocity);

        void SetAccelerationVelocity(const sf::Vector2f &newVelocity);

        sf::Vector2f GetAccelerationVelocity() const { return mAccelerationVelocity; };

        virtual void Shoot();

        void BeginPlay() override;

    private:
        sf::Vector2f mVelocity;
        float mRotationVelocity;
        sf::Vector2f mAccelerationVelocity;
    };

}

