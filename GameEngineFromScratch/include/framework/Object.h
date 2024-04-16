#pragma once

namespace ly {


    class Object {
    public:
        Object();
        ~Object();
        virtual void Destroy();

        bool IsPendingDestroy() const {
            return mIsPendingDestroy;
        }

    private:
        bool mIsPendingDestroy;

    };

}
