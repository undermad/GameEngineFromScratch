#include "enemy/EnemySpaceship.h"


namespace ly {


    EnemySpaceship::EnemySpaceship(World *owningWorld, const std::string &texturePath, float collisionDamage)
            : Spaceship(owningWorld, texturePath),
              mCollisionDamage(collisionDamage) {
    }

    void EnemySpaceship::Tick(float deltaTime) {
        Spaceship::Tick(deltaTime);
        if(IsActorOutOfWindowBounds(GetActorGlobalBounds().width / 2)) {
            Destroy();
        }
    }

    void EnemySpaceship::OnActionBeginOverlap(Actor *other) {
        Actor::OnActionBeginOverlap(other);

        if (IsOtherHostile(other)) {
            other->ApplayDamage(mCollisionDamage);
        }

    }


}