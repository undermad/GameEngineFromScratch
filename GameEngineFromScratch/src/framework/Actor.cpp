#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"
#include "framework/Physics.h"

namespace ly {

    Actor::Actor(World *owningWorld, const std::string &texturePath)
            : mOwningWorld(owningWorld),
              mHasBeginPlay(false),
              mSprite(),
              mTexture(),
              mPhysicBody(nullptr),
              mPhysicsEnabled(false),
              mTeamId(GetNeturalTeamId())
              {
        SetTexture(texturePath);
    }

    Actor::~Actor() {
    }

    void Actor::BeginPlayInternal() {
        if (!mHasBeginPlay) {
            mHasBeginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay() {
    }

    void Actor::TickInternal(float deltaTime) {
        if (!IsPendingDestroy()) {
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

        if (IsPendingDestroy())
            return;

        window.draw(mSprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f &newLocation) {
        mSprite.setPosition(newLocation);
        UpdatePhysicBodyTransform();
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

    sf::Vector2u Actor::GetWindowSize() const {
        return mOwningWorld->GetWindowSize();
    }

    bool Actor::IsActorOutOfWindowBounds() const {
        float windowWidth = GetWindowSize().x;
        float windowHeight = GetWindowSize().y;

        float objectWidth = GetActorGlobalBounds().width;
        float objectHeight = GetActorGlobalBounds().height;

        sf::Vector2f actorPosition = GetActorLocation();

        if (actorPosition.x<-objectWidth || actorPosition.x>(windowWidth + objectWidth)) return true;
        if (actorPosition.y<-objectHeight || actorPosition.y>(windowHeight + objectHeight)) return true;
        return false;
    }

    sf::FloatRect Actor::GetActorGlobalBounds() const {
        return mSprite.getGlobalBounds();
    }

    void Actor::SetEnablePhysics(bool enable) {
        mPhysicsEnabled = enable;
        if (mPhysicsEnabled) {
            InitializePhysics();
        } else {
            UnInitializePhysics();
        }

    }

    void Actor::InitializePhysics() {
        if (!mPhysicBody) {
            mPhysicBody = Physics::Get().AddListener(this);
        }
    }

    void Actor::UnInitializePhysics() {
        if (mPhysicBody) {
            Physics::Get().RemoveListener(mPhysicBody);
            mPhysicBody = nullptr;
        }
    }

    void Actor::UpdatePhysicBodyTransform() {
        if (mPhysicBody) {
            float physicsScale = Physics::Get().GetPhysicScale();
            b2Vec2 position{GetActorLocation().x * physicsScale, GetActorLocation().y * physicsScale};
            float rotation = DegreesToRadians(GetActorRotation());

            mPhysicBody->SetTransform(position, rotation);
        }
    }

    void Actor::OnActionBeginOverlap(Actor *other) {

    }

    void Actor::OnActionEndOverlap(Actor *other) {

    }

    void Actor::Destroy() {
        UnInitializePhysics();
        Object::Destroy();
    }

    bool Actor::IsOtherHostile(Actor *other) const {
        if(GetTeamId() == other->GetTeamId() || other->GetTeamId() == GetNeturalTeamId()) {
            return false;
        }
        return true;
    }

    void Actor::ApplayDamage(float amount) {

    }

}
