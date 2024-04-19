#pragma once


#include "framework/Actor.h"

namespace ly {

    class Particle : public Actor {
    public:
        Particle(World *owningWorld, const std::string &texturePath);

        void Tick(float deltaTime) override;

        void RandomVelocity(float minSpeed, float maxSpeed);

        void RandomSize(float min, float max);

        void RandomLifeTime(float min, float max);

        void Move(float deltaTime);

        void Fade(float deltaTime);

    private:
        sf::Vector2f mVelocity;
        float mLifeTime;
        sf::Clock mTimer;
    };

}
