#pragma once


#include "spaceship/Spaceship.h"
#include "weapon/BulletShooter.h"


namespace ly {

    class BulletShooter;
    class PlayerSpaceship : public Spaceship {

    public:
        PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

        void Tick(float deltaTime) override;
        void HandleInput();
        void setSpeed(float newSpeed) { mSpeed = newSpeed; };
        float getSpeed() { return mSpeed; };

        void Shoot() override;



    private:
        sf::Vector2f mMoveInput;
        float mSpeed;

        sf::Vector2f mAccelerateValue;
        float mAccleerateSpeed;

        float mRotationValue;
        float mRotationSpeed;

        void Accelerate();
        void NormalizeInput();
        void ClampInputOnEdge();
        void ConsumeInput(float deltaTime);
        void CleanInput();

        unique<BulletShooter> mBulletShooter;

    };
}
