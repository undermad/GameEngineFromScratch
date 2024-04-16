#pragma once
#include <framework/Application.h>
#include "player/PlayerSpaceship.h"

namespace ly
{
	class GameApplication : public Application
	{
    public:
        GameApplication();
        virtual void Tick(float deltaTime) override;

    private:
        float counter;
        weak<PlayerSpaceship> testPlayer;
	};
}
