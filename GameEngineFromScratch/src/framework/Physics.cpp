#include <box2d/b2_contact.h>

#include "framework/Physics.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

namespace ly {

    unique<Physics> Physics::mPhysics{nullptr};

    Physics &Physics::Get() {
        if (!mPhysics) {
            mPhysics = std::move(unique<Physics>{new Physics});
        }
        return *mPhysics;
    }

    Physics::Physics()
            : mPhysicWorld(b2Vec2{0.f, 0.f}),
              mPhysicScale(0.01f),
              mVelocityIterations(8),
              mPositionIterations(3),
              mPhysicsContactListener(),
              mPendingRemoveListeners() {

        mPhysicWorld.SetContactListener(&mPhysicsContactListener);
        mPhysicWorld.SetAllowSleeping(false);
    }

    void Physics::Step(float deltaTime) {
        ProcessPendingRemoveListeners();
        mPhysicWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
    }

    b2Body *Physics::AddListener(Actor *listener) {
        if (listener->IsPendingDestroy()) return nullptr;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);
        bodyDef.position.Set(listener->GetActorLocation().x * GetPhysicScale(),
                             listener->GetActorLocation().y * GetPhysicScale());
        bodyDef.angle = DegreesToRadians(listener->GetActorRotation());

        b2Body *body = mPhysicWorld.CreateBody(&bodyDef);

        b2PolygonShape shape;
        auto bound = listener->GetActorGlobalBounds();
        shape.SetAsBox(bound.width / 2.f * GetPhysicScale(), bound.height / 2.f * GetPhysicScale());

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.isSensor = true;

        body->CreateFixture(&fixtureDef);

        return body;
    }

    void Physics::RemoveListener(b2Body *bodyToRemove) {

        mPendingRemoveListeners.insert(bodyToRemove);
    }

    void Physics::ProcessPendingRemoveListeners() {
        for (auto listener: mPendingRemoveListeners) {
            mPhysicWorld.DestroyBody(listener);
        }
        mPendingRemoveListeners.clear();
    }

    void Physics::Cleanup() {
        mPhysics = std::move(unique<Physics>{new Physics});
    }

    void PhysicsContactListener::BeginContact(b2Contact *contact) {
        Actor *ActorA = reinterpret_cast<Actor *>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        Actor *ActorB = reinterpret_cast<Actor *>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

        if (ActorA && !ActorA->IsPendingDestroy()) {
            ActorA->OnActionBeginOverlap(ActorB);
        }
        if (ActorB && !ActorB->IsPendingDestroy()) {
            ActorB->OnActionBeginOverlap(ActorA);
        }

    }

    void PhysicsContactListener::EndContact(b2Contact *contact) {

        Actor *ActorA = nullptr;
        Actor *ActorB = nullptr;

        if (contact->GetFixtureA() && contact->GetFixtureA()) {
            ActorA = reinterpret_cast<Actor *>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        }

        if (contact->GetFixtureB() && contact->GetFixtureB()) {
            ActorB = reinterpret_cast<Actor *>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
        }

        if (ActorA && !ActorA->IsPendingDestroy()) {
            ActorA->OnActionEndOverlap(ActorB);
        }

        if (ActorB && !ActorB->IsPendingDestroy()) {
            ActorB->OnActionEndOverlap(ActorA);
        }


    }
}