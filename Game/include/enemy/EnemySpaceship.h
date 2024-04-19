#pragma once


#include "spaceship/Spaceship.h"

namespace ly {
    class EnemySpaceship : public Spaceship {

    public:
        EnemySpaceship(World* owningWorld, const std::string& texturePath, float collisionDamage = 50);
        void Tick(float deltaTime) override;

    private:
        float mCollisionDamage;
    public:
        void OnActionBeginOverlap(Actor *other) override;


    };
}

