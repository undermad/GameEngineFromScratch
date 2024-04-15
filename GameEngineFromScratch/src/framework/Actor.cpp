#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"

namespace ly {

    Actor::Actor(World *owningWorld, const std::string &texturePath)
            : owningWorld(owningWorld),
              mHasBeginPlay(false),
              mSprite(),
              mTexture() {
        SetTexture(texturePath);
    }

    Actor::~Actor() {
        LOG("Destroying Actor");
    }

    void Actor::BeginPlayInternal() {
        if (!mHasBeginPlay) {
            mHasBeginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay() {
        LOG("Actor began the game!");
    }

    void Actor::TickInternal(float deltaTime) {
        if (!isPendingDestroy()) {
            Tick(deltaTime);
        }
    }

    void Actor::Tick(float deltaTime) {

    }

    void Actor::SetTexture(const std::string &texturePath) {

        mTexture = AssetManager::GetInstance().LoadTexture(texturePath);
        if (!mTexture) return;

        mSprite.setTexture(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int textureHeight = mTexture->getSize().y;
        mSprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
        CenterPivot();
    }

    void Actor::Render(sf::RenderWindow &window) {

        if (isPendingDestroy())
            return;

        window.draw(mSprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f &newLocation) {
        mSprite.setPosition(newLocation);
    }

    void Actor::SetActorRotation(float newRotation) {
        mSprite.setRotation(newRotation);
    }

    void Actor::AddActorLocationOffset(const sf::Vector2f &offset) {
        SetActorLocation(GetActorLocation() + offset);
    }

    void Actor::AddActorRotationOffest(float offset) {
        SetActorRotation(GetActorRotation() + offset);
    }

    sf::Vector2f Actor::GetActorLocation() const {
        return mSprite.getPosition();
    }

    float Actor::GetActorRotation() {
        return mSprite.getRotation();
    }

    sf::Vector2f Actor::GetActorForwardDirection() {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDirection() {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    void Actor::CenterPivot() {
        sf::FloatRect bound = mSprite.getGlobalBounds();
        mSprite.setOrigin(bound.width / 2.f, bound.height / 2.f);
    }


}
