#include "player/PlayerSpaceship.h"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace ly {


    PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
            : Spaceship(owningWorld, path),
              mMoveInput(),
              mAccleerateSpeed(200),
              mSpeed(200),
              mRotationValue(0),
              mRotationSpeed(400),
              mBulletShooter(new BulletShooter(this, 0.3f)) {
    }

    void PlayerSpaceship::Tick(float deltaTime) {
        Spaceship::Tick(deltaTime);
        HandleInput();
        ClampInputOnEdge();
        NormalizeInput();
        ConsumeInput(deltaTime);
        CleanInput();
    }

    void PlayerSpaceship::HandleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            Accelerate();
            if (mAccleerateSpeed <= 500) mAccleerateSpeed += 15;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            mMoveInput.y = 1.f;
        } else {
            if (mAccleerateSpeed >= 50) mAccleerateSpeed -= 25;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mRotationValue = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            mRotationValue = 1.f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
            Shoot();
        }


    }

    void PlayerSpaceship::ConsumeInput(float deltaTime) {
        SetVelocity(mMoveInput * mSpeed);
        SetRotationVelocity(mRotationValue * mRotationSpeed);
        SetAccelerationVelocity(mAccelerateValue);
    }

    void PlayerSpaceship::CleanInput() {
        mMoveInput.x = mMoveInput.y = 0.f;
        mRotationValue = 0;
    }

    void PlayerSpaceship::NormalizeInput() {
        Normalize(mMoveInput);
    }

    void PlayerSpaceship::ClampInputOnEdge() {
        sf::Vector2f actorLocation = GetActorLocation();
        if (actorLocation.x < 0 && mMoveInput.x == -1) {
            mMoveInput.x = 0.f;
        }
        if (actorLocation.x > GetWindowSize().x && mMoveInput.x == 1) {
            mMoveInput.x = 0.f;
        }
        if (actorLocation.y < 0 && mMoveInput.y == -1) {
            mMoveInput.y = 0.f;
        }
        if (actorLocation.y > GetWindowSize().y && mMoveInput.y == 1) {
            mMoveInput.y = 0.f;
        }

    }

    void PlayerSpaceship::Accelerate() {
        LOG("X: %f, Y: %f", mAccelerateValue.x, mAccelerateValue.y);
        mAccelerateValue = RotationToVector(GetActorRotation()) * mAccleerateSpeed;
    }

    void PlayerSpaceship::Shoot() {
        if(mBulletShooter) {
            mBulletShooter->Shoot();
        }
    }


}