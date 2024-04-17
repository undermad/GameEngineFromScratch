#include "weapon/Bullet.h"

ly::Bullet::Bullet(ly::World *owningWorld, ly::Actor *owner, const std::string &texturePath, float speed, float damage)
        : Actor(owningWorld, texturePath),
          mSpeed(speed),
          mDamage(damage) {
    SetTeamId(owner->GetTeamId());
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

void ly::Bullet::BeginPlay() {
    Actor::BeginPlay();

    SetEnablePhysics(true);
}

void ly::Bullet::OnActionBeginOverlap(Actor *other) {
    if(IsOtherHostile(other)) {
        other->ApplayDamage(GetDamage());
        Destroy();
    }
}
