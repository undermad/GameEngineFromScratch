#include "VFX/Explosion.h"
#include "framework/MathUtility.h"
#include "VFX/Particle.h"

namespace ly {


    Explosion::Explosion(int particleAmount, float lifeTimeMin, float lifeTimeMax, float sizeMin, float sizeMax,
                         float speedMin, float speedMax, sf::Color color, const List<std::string> &particleImagePaths)
            :
            mParticleAmount(particleAmount),
            mLifeTimeMin(lifeTimeMin),
            mLifeTimeMax(lifeTimeMax),
            mSizeMin(sizeMin),
            mSizeMax(sizeMax),
            mSpeedMin(speedMin),
            mSpeedMax(speedMax),
            mColor(color),
            mParticleImagePaths(particleImagePaths) {

    }

    void Explosion::SpawnExplosion(World *world, const sf::Vector2f& location) {

        if (world) {
            for (int i = 0; i < mParticleAmount; i++) {
                std::string particleImagePath = mParticleImagePaths[(int) RandomRange(0, mParticleImagePaths.size())];
                weak<Particle> newParticle = world->SpawnActor<Particle>(particleImagePath);

                newParticle.lock()->SetActorLocation(location);
                newParticle.lock()->RandomLifeTime(mLifeTimeMin, mLifeTimeMax);
                newParticle.lock()->RandomSize(mSizeMin, mSizeMax);
                newParticle.lock()->RandomVelocity(mSpeedMin, mSpeedMax);
                newParticle.lock()->GetSprite().setColor(mColor);
            }
        }
    }


}