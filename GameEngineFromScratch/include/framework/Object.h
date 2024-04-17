#pragma once

#include <memory>
#include "framework/Core.h"
#include "Delegate.h"

namespace ly {


    class Object : public std::enable_shared_from_this<Object> {
    public:
        Object();

        ~Object();

        Delegate<Object*> onDestroy;

        virtual void Destroy();

        weak<Object> GetWeakRef() { return weak_from_this(); };

        weak<const Object> GetWeakRef() const { return weak_from_this(); };

        bool IsPendingDestroy() const {
            return mIsPendingDestroy;
        }

    private:
        bool mIsPendingDestroy;

    };

}
