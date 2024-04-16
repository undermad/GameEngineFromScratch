#pragma once

#include "framework/Actor.h"

namespace ly {

    class Bullet : public Actor {
    public:
        Bullet(World* owningWorld, Actor* owner, const std::string& texturePath, float speed = 1000, float damage = 200);

        void SetSpeed(float speed) { mSpeed = speed; };
        void SetDamage(float damage) { mDamage = damage; };
        float GetSpeed() const { return mSpeed; };
        float GetDamag() const { return mDamage; };

        void Tick(float deltaTime) override;

        void BeginPlay() override;

    private:
        Actor* mOwner;
        float mSpeed;
        float mDamage;
        void Move(float deltaTime);
    };
}
