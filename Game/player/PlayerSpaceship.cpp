#include "PlayerSpaceship.h"
#include "framework/MathUtility.h"

namespace ly {


    PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
            : Spaceship(owningWorld, path),
              mMoveInput(),
              mSpeed(600),
              mRotationSpeed(0),
              mAccleerateSpeed(500){

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            Accelerate();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            mMoveInput.y = 1.f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mRotationSpeed = -1.f;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            mRotationSpeed = 1.f;
        }
    }

    void PlayerSpaceship::ConsumeInput(float deltaTime) {
        SetVelocity(mMoveInput * mSpeed);
        SetRotationVelocity(mRotationSpeed * mSpeed);
        SetAccelerationVelocity(mAccelerateValue);
    }

    void PlayerSpaceship::CleanInput() {
        mMoveInput.x = mMoveInput.y = 0.f;
        mRotationSpeed = 0;
    }

    void PlayerSpaceship::NormalizeInput() {
        Normalize(mMoveInput);
    }

    void PlayerSpaceship::ClampInputOnEdge() {
        sf::Vector2f actorLocation = GetActorLocation();
        if(actorLocation.x < 0 && mMoveInput.x == -1) {
            mMoveInput.x = 0.f;
        }
        if(actorLocation.x > GetWindowSize().x && mMoveInput.x == 1){
            mMoveInput.x = 0.f;
        }
        if(actorLocation.y < 0 && mMoveInput.y == -1) {
            mMoveInput.y = 0.f;
        }
        if(actorLocation.y > GetWindowSize().y && mMoveInput.y == 1) {
            mMoveInput.y = 0.f;
        }

        LOG("X: %f, Y: %f", GetActorLocation().x, GetActorLocation().y);
        LOG("Angle: %f", GetActorRotation());

    }

    void PlayerSpaceship::Accelerate() {

        LOG("X: %f, Y: %f", mAccelerateValue.x, mAccelerateValue.y);
        mAccelerateValue = sf::Vector2f(
                sin(GetActorRotation() * GetPI() / 180) * mAccleerateSpeed,
                -cos(GetActorRotation() * GetPI() / 180) * mAccleerateSpeed);
    }



}