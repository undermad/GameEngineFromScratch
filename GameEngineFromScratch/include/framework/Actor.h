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

        void setTexture(const std::string& texturePath);
        void BeginPlayInternal();
        virtual void BeginPlay();
        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);
        void Render(sf::RenderWindow& window);

    private:
        World *owningWorld;
        bool mHasBeginPlay;

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

    };

}

