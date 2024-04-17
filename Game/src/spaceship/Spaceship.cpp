#include "spaceship/Spaceship.h"
#include "framework/MathUtility.h"


namespace ly {


    Spaceship::Spaceship(World *owningWorld, const std::string &texturePath)
            : Actor(owningWorld, texturePath),
              mHealthComponent(100,100)
            {

    }

    void Spaceship::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(mAccelerationVelocity * deltaTime);
        AddActorRotationOffest(mRotationVelocity * deltaTime);
    }

    void Spaceship::SetVelocity(const sf::Vector2f &newVelocity) {
        mVelocity = newVelocity;
    }

    void Spaceship::SetRotationVelocity(float newVelocity) {
        mRotationVelocity = newVelocity;
    }

    void Spaceship::SetAccelerationVelocity(const sf::Vector2f& newVelocity) {
        mAccelerationVelocity = newVelocity;
    }

    void Spaceship::Shoot() {

    }

    void Spaceship::BeginPlay() {
        Actor::BeginPlay();
        SetEnablePhysics(true);
        mHealthComponent.onHealthChange.BindAction(GetWeakRef(), &Spaceship::OnHealthChange);
        mHealthComponent.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
        mHealthComponent.onHealthEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);
    }


    void Spaceship::ApplayDamage(float amount) {
        mHealthComponent.ChangeHealth(-amount);
    }

    void Spaceship::OnHealthChange(float amount, float health, float maxHealth) {
        LOG("Health changed by: %f, now is: %f. Max Health: %f", amount, health, maxHealth );
    }

    void Spaceship::OnTakenDamage(float amount, float health, float maxHealth) {

    }

    void Spaceship::Blow() {
        Destroy();
    }


}