#pragma once


#include "Object.h"
#include "Core.h"
#include <SFML/Graphics.hpp>

namespace ly {

    class World;

    class Actor : public Object {

    public:
        explicit Actor(World *owningWorld, const std::string& texturePath = "");
        ~Actor();

        void SetTexture(const std::string& texturePath);
        void BeginPlayInternal();
        virtual void BeginPlay();
        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);
        void Render(sf::RenderWindow& window);
        void SetActorLocation(const sf::Vector2f& newLocation);
        void SetActorRotation(float newRotation);
        void AddActorLocationOffset(const sf::Vector2f& offset);
        void AddActorRotationOffest(float offset);
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation();
        sf::Vector2f GetActorForwardDirection();
        sf::Vector2f GetActorRightDirection();
    private:
        World *owningWorld;
        bool mHasBeginPlay;
        void CenterPivot();

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

    };

}

