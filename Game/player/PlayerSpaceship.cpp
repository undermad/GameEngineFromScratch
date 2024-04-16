#include "PlayerSpaceship.h"
#include "framework/MathUtility.h"

namespace ly {


    PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
            : Spaceship(owningWorld, path),
            mMoveInput(),
            mSpeed(600) {

    }

    void PlayerSpaceship::Tick(float deltaTime) {
        Spaceship::Tick(deltaTime);
        HandleInput();
        ConsumeInput(deltaTime);
    }

    void PlayerSpaceship::HandleInput() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            mMoveInput.y = -1.f;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            mMoveInput.y = 1.f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            mMoveInput.x = -1.f;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            mMoveInput.x = 1.f;
        }


        ClampInputOnEdge();
        NormalizeInput();
    }

    void PlayerSpaceship::ConsumeInput(float deltaTime) {
        SetVelocity(mMoveInput * mSpeed);
        mMoveInput.x = mMoveInput.y = 0.f;
    }

    void PlayerSpaceship::NormalizeInput() {
        Normalize(mMoveInput);
//        LOG("Move input x: %f, y: %f", mMoveInput.x, mMoveInput.y );
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


    }
}