#pragma once


#include "spaceship/Spaceship.h"

namespace ly {

    class PlayerSpaceship : public Spaceship {

    public:
        PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

        void Tick(float deltaTime) override;
        void HandleInput();
        void setSpeed(float newSpeed) { mSpeed = newSpeed; };
        float getSpeed() { return mSpeed; };
    private:
        sf::Vector2f mMoveInput;
        void NormalizeInput();
        void ClampInputOnEdge();
        float mSpeed;
        void ConsumeInput(float deltaTime);

    };
}
