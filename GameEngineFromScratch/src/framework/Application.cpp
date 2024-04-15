#include "framework/Application.h"

namespace ly {
    Application::Application(unsigned int windowWidth, unsigned windowHeight, const std::string& windowTitle, sf::Uint32 style)
            : mWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle, style),
              mTargetFrameRate(60.0f),
              mTickClock(),
              currentWorld(nullptr) {
    }

    void Application::Run() {
        mTickClock.restart();
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / mTargetFrameRate;

        while (mWindow.isOpen()) {
            sf::Event windowEvent{};
            while (mWindow.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::EventType::Closed) {
                    mWindow.close();
                }
            }

            float frameDeltaTime = mTickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;

            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::TickInternal(float deltaTime) {

        Tick(deltaTime);

        if (currentWorld) {
            currentWorld->TickInternal(deltaTime);
        }
    }

    void Application::Tick(float deltaTime) {

    }

    void Application::RenderInternal() {
        mWindow.clear();
        Render();
        mWindow.display();
    }

    void Application::Render() {


        if(currentWorld) {
            currentWorld->Render(mWindow);
        }

    }


}
