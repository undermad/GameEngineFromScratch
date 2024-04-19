#pragma once

#include "framework/Actor.h"

namespace ly {

    class Bullet : public Actor {
    public:
        Bullet(World* owningWorld, Actor* owner, const std::string& texturePath, float speed = 1000, float damage = 60);

        void SetSpeed(float speed) { mSpeed = speed; };
        void SetDamage(float damage) { mDamage = damage; };
        float GetSpeed() const { return mSpeed; };
        float GetDamage() const { return mDamage; };

        void Tick(float deltaTime) override;

        void BeginPlay() override;

    private:

    public:
        void OnActionBeginOverlap(Actor *other) override;

    private:
        Actor* mOwner;
        float mSpeed;
        float mDamage;
        void Move(float deltaTime);
    };
}
