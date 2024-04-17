#include "framework/Object.h"
#include "framework/Core.h"


namespace ly {

    Object::Object()
        : mIsPendingDestroy{ false }
    {

    }

    Object::~Object() {
        LOG("Destroying the object");
    }

    void Object::Destroy() {
        onDestroy.Broadcast(this);
        mIsPendingDestroy = true;
    }
}
