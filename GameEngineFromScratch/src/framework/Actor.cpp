#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"

namespace ly {

    Actor::Actor(World *owningWorld, const std::string& texturePath)
        : owningWorld(owningWorld),
        mHasBeginPlay(false),
        mSprite(),
        mTexture()
    {
        setTexture(texturePath);
    }

    Actor::~Actor() {
        LOG("Destroying Actor");
    }

    void Actor::BeginPlayInternal() {
        if(!mHasBeginPlay) {
            mHasBeginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay() {
        LOG("Actor began the game!");
    }

    void Actor::TickInternal(float deltaTime) {
        if(!isPendingDestroy()){
            Tick(deltaTime);
        }
    }

    void Actor::Tick(float deltaTime) {

    }

    void Actor::setTexture(const std::string& texturePath) {

        mTexture = AssetManager::GetInstance().LoadTexture(texturePath);
        if(!mTexture) return;

        mSprite.setTexture(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int textureHeight = mTexture->getSize().y;
        mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{ textureWidth, textureHeight } });
    }

    void Actor::Render(sf::RenderWindow &window) {

        if(isPendingDestroy())
            return;

        window.draw(mSprite);
    }



}
