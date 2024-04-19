#include "spaceship/Spaceship.h"
#include "framework/MathUtility.h"
#include "VFX/Explosion.h"


namespace ly {


    Spaceship::Spaceship(World *owningWorld, const std::string &texturePath)
            : Actor(owningWorld, texturePath),
              mHealthComponent(100,100),
              mBlinkTime(0),
              mBlinkDuration(0.2f),
              mBlinkColorOffset(255,0,0, 255)
            {

    }

    void Spaceship::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(mAccelerationVelocity * deltaTime);
        AddActorRotationOffest(mRotationVelocity * deltaTime);
        UpdateBlink(deltaTime);
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

    void Spaceship::ApplayDamage(float amount) {
        mHealthComponent.ChangeHealth(-amount);
    }

    void Spaceship::BeginPlay() {
        Actor::BeginPlay();
        SetEnablePhysics(true);
        mHealthComponent.onHealthChange.BindAction(GetWeakRef(), &Spaceship::OnHealthChange);
        mHealthComponent.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
        mHealthComponent.onHealthEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);
    }

    void Spaceship::OnHealthChange(float amount, float health, float maxHealth) {
        LOG("Health changed by: %f, now is: %f. Max Health: %f", amount, health, maxHealth );
    }

    void Spaceship::OnTakenDamage(float amount, float health, float maxHealth) {
        Blink();
    }

    void Spaceship::Blow() {
        Explosion* explosion = new Explosion();
        explosion->SpawnExplosion(GetWorld(), GetActorLocation());
        Destroy();
        delete explosion;
    }

    void Spaceship::Blink() {
        if(mBlinkTime == 0) mBlinkTime = mBlinkDuration;

    }

    void Spaceship::UpdateBlink(float deltaTime) {
        if(mBlinkTime > 0) mBlinkTime -= deltaTime;
        mBlinkTime = mBlinkTime > 0 ? mBlinkTime : 0.f;

        GetSprite().setColor(LerpColor(sf::Color::White, mBlinkColorOffset, mBlinkTime));
    }


}