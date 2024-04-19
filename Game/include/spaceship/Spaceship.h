#pragma once


#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"

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

        void ApplayDamage(float amount) override;

        virtual void Shoot();

        void BeginPlay() override;

    private:
        sf::Vector2f mVelocity;
        float mRotationVelocity;
        sf::Vector2f mAccelerationVelocity;
        HealthComponent mHealthComponent;
        virtual void OnHealthChange(float amount, float health, float maxHealth);
        virtual void OnTakenDamage(float amount, float health, float maxHealth);
        virtual void Blow();

        float mBlinkTime;
        float mBlinkDuration;
        sf::Color mBlinkColorOffset;
        void Blink();
        void UpdateBlink(float deltaTime);
    };

}

