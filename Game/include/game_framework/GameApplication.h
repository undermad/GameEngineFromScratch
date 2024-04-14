#pragma once
#include <framework/Application.h>

namespace ly
{
	class GameApplication : public Application
	{
    public:
        GameApplication();

    private:
        float counter;
        weak<Actor> actorToDestroy;
	};
}
