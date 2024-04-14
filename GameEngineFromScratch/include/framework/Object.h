#pragma once

namespace ly {


    class Object {
    public:
        Object();
        ~Object();
        void Destroy();

        bool isPendingDestroy() const {
            return mIsPendingDestroy;
        }

    private:
        bool mIsPendingDestroy;

    };

}
