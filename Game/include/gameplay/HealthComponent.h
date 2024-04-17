#pragma once

#include "framework/Actor.h"
#include "framework/Delegate.h"

namespace ly {
    class HealthComponent {
    public:
        HealthComponent(float health, float maxHealth);
        void ChangeHealth(float amount);
        float GetHealth() const { return mHealth; };
        float GetMaxHealth() const { return mMaxHealth; };

        Delegate<float, float, float> onHealthChange;
        Delegate<float, float, float> onTakenDamage;
        Delegate<> onHealthEmpty;

    private:
        float mHealth;
        float mMaxHealth;
        void TakenDamage(float amount);
        void HealthEmpty();

    };
}
