#pragma once


#include "Object.h"
#include "Core.h"
#include "box2d/b2_body.h"
#include "box2d/b2_world_callbacks.h"
#include <SFML/Graphics.hpp>

class b2Body;

namespace ly {

    class World;

    class Actor : public Object {

    public:
        explicit Actor(World *owningWorld, const std::string &texturePath = "");

        ~Actor();

        void SetTexture(const std::string &texturePath);

        void BeginPlayInternal();

        virtual void BeginPlay();

        void TickInternal(float deltaTime);

        virtual void Tick(float deltaTime);

        void Render(sf::RenderWindow &window);

        void SetActorLocation(const sf::Vector2f &newLocation);

        void SetActorRotation(float newRotation);

        void AddActorLocationOffset(const sf::Vector2f &offset);

        void AddActorRotationOffest(float offset);

        sf::Vector2f GetActorLocation() const;

        float GetActorRotation();

        sf::Vector2f GetActorForwardDirection();

        sf::Vector2f GetActorRightDirection();

        sf::Vector2u GetWindowSize() const;

        const World *GetWorld() const { return mOwningWorld; };

        World *GetWorld() { return mOwningWorld; };


        bool IsActorOutOfWindowBounds(float allowance = 10.f) const;

        sf::FloatRect GetActorGlobalBounds() const;

        static uint8 GetNeturalTeamId() { return neturailTeamId; };

        void SetEnablePhysics(bool enable);

        void SetTeamId(uint8 teamId) { mTeamId = teamId; };

        virtual void ApplayDamage(float amount);

        virtual void OnActionBeginOverlap(Actor *other);

        virtual void OnActionEndOverlap(Actor *other);

        uint8 GetTeamId() const { return mTeamId; };

        bool IsOtherHostile(Actor *other) const;

        sf::Sprite &GetSprite() { return mSprite; };

        const sf::Sprite &GetSprite() const { return mSprite; };

        void Destroy() override;

    private:
        World *mOwningWorld;
        bool mHasBeginPlay;

        uint8 mTeamId;

        void CenterPivot();

        void UnInitializePhysics();

        void InitializePhysics();

        void UpdatePhysicBodyTransform();

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;
        b2Body *mPhysicBody;

        bool mPhysicsEnabled;

        const static uint8 neturailTeamId = 255;
    };

}

