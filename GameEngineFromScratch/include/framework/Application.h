#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Core.h"


namespace ly
{
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned windowHeight, const std::string& windowTitle, sf::Uint32 style);
		void Run();

        template<typename WorldType>
        weak<WorldType> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		virtual void Tick(float deltaTime);
		void RenderInternal();
		virtual void Render();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;

        shared<World> currentWorld;
	};


    template<typename WorldType>
    weak<WorldType> Application::LoadWorld(){
        shared<World> newWorld{ new WorldType{this} };
        currentWorld = newWorld;
        currentWorld->BeginPlayInternal();
        return newWorld;
    }
}
