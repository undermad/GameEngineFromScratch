#pragma once
#include <framework/Application.h>

namespace ly
{
	class GameApplication : public Application
	{
    public:
        GameApplication();
        virtual void Tick(float deltaTime) override;

    private:
        float counter;
        weak<Actor> mActorToDestroy;
	};
}
