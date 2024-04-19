#pragma once

#include <string>

#include "framework/World.h"
#include "framework/Core.h"


namespace ly {

    class Explosion {


    public:
        Explosion(int particleAmount = 10,
                           float lifeTimeMin = 1.f,
                           float lifeTimeMax = 4.f,
                           float sizeMin = 1,
                           float sizeMax = 3,
                           float speedMin = 100,
                           float speedMax = 150,
                           sf::Color color = sf::Color(255, 128, 8, 255),
                           const List<std::string> &particleImagePaths = {
                                   "SpaceShooterRedux/PNG/Effects/star1.png",
                                   "SpaceShooterRedux/PNG/Effects/star2.png",
                                   "SpaceShooterRedux/PNG/Effects/star3.png"}
        );

        void SpawnExplosion(World *world, const sf::Vector2f &location);

    private:
        int mParticleAmount;
        int mDuration;
        List<std::string> mParticleImagePaths;
        float mLifeTimeMin;
        float mLifeTimeMax;
        float mSizeMax;
        float mSizeMin;
        float mSpeedMax;
        float mSpeedMin;
        sf::Color mColor;
    };

}
