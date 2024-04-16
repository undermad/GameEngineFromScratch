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

        World *GetWorld() const { return mOwningWorld; };

        bool IsActorOutOfWindowBounds() const;

        sf::FloatRect GetActorGlobalBounds() const;

        void SetEnablePhysics(bool enable);

        virtual void OnActionBeginOverlap(Actor* other);
        virtual void OnActionEndOverlap(Actor* other);

        void Destroy() override;

    private:
        World *mOwningWorld;
        bool mHasBeginPlay;

        void CenterPivot();

        void UnInitializePhysics();

        void InitializePhysics();

        void UpdatePhysicBodyTransform();

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;
        b2Body *mPhysicBody;

        bool mPhysicsEnabled;
    };

}

