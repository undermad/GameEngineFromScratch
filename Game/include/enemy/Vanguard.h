#pragma once

#include "enemy/EnemySpaceship.h"

namespace ly {

    class BulletShooter;
    class Vanguard : public EnemySpaceship {

    public:
        Vanguard(World* owningWorld,
                 const std::string& texturePath = "SpaceShooterRedux/PNG/Enemies/enemyBlack1.png",
                 const sf::Vector2f& velocity = sf::Vector2f(0.f, 100.f));

        void Shoot() override;

        void Tick(float deltaTime) override;

    private:
        unique<BulletShooter> mShooter;


    };
}
