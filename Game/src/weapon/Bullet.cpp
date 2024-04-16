#include "weapon/Bullet.h"

ly::Bullet::Bullet(ly::World *owningWorld, ly::Actor *owner, const std::string &texturePath, float speed, float damage)
        : Actor(owningWorld, texturePath),
          mSpeed(speed),
          mDamage(damage) {

}

void ly::Bullet::Tick(float deltaTime) {
    Actor::Tick(deltaTime);
    Move(deltaTime);
    if (IsActorOutOfWindowBounds()) {
        Destroy();
    }

}

void ly::Bullet::Move(float deltaTime) {
    AddActorLocationOffset(GetActorForwardDirection() * mSpeed * deltaTime);
}
