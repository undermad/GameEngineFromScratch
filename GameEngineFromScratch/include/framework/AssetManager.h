#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"


namespace ly {

class AssetManager {

public:
    static AssetManager& GetInstance();
    shared<sf::Texture> LoadTexture(const std::string& path);
    void CleanCycle();

protected:
    AssetManager();

private:
    static unique<AssetManager> mAssetManager;
    Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
};

}
