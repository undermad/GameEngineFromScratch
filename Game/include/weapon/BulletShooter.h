#pragma once


#include "Shooter.h"
#include <SFML/System.hpp>

namespace ly {

    class BulletShooter : public Shooter {
    public:
        BulletShooter(Actor* owner, float cooldownTime = 0.3f);

        bool IsOnCooldown() const override;

    private:
        void ShootImpl() override;

    private:
        sf::Clock mCooldownClock;
        float mCooldownTime;
    };

}
