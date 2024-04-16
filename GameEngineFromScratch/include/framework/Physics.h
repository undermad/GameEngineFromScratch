#pragma once


#include "Core.h"
#include "Actor.h"
#include <box2d/b2_world.h>

namespace ly {

    class PhysicsContactListener : public b2ContactListener {

    public:
        void BeginContact(b2Contact *contact) override;

        void EndContact(b2Contact *contact) override;
    };

    class Physics {
    public:
        static Physics &Get();

        void Step(float deltaTime);

        b2Body *AddListener(Actor *listener);

        void RemoveListener(b2Body *bodyToRemove);

        float GetPhysicScale() const { return mPhysicScale; };

        static void Cleanup();


    protected:
        Physics();

    private:
        static unique<Physics> mPhysics;
        b2World mPhysicWorld;
        float mPhysicScale;
        int mVelocityIterations;
        int mPositionIterations;
        PhysicsContactListener mPhysicsContactListener;
        void ProcessPendingRemoveListeners();

        Set<b2Body*> mPendingRemoveListeners;
    };
}

