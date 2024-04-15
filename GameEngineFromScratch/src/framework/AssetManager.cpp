#include "framework/AssetManager.h"


namespace ly {

    unique<AssetManager> AssetManager::mAssetManager{nullptr};

    AssetManager::AssetManager() = default;

    AssetManager &AssetManager::GetInstance() {
        if (!mAssetManager) {
            mAssetManager = unique<AssetManager>{new AssetManager};
        }
        return *mAssetManager;
    }

    shared<sf::Texture> AssetManager::LoadTexture(const std::string &path) {

        auto found = mLoadedTextureMap.find(path);
        if (found != mLoadedTextureMap.end()) {
            return found->second;
        }

        shared<sf::Texture> newTexture{new sf::Texture};
        if (newTexture->loadFromFile(path)) {
            mLoadedTextureMap.insert({path, newTexture});
            return newTexture;
        }

        return shared<sf::Texture>{nullptr};


    }

    void AssetManager::CleanCycle() {
        for (auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();) {
            if(iter->second.unique()){
                iter = mLoadedTextureMap.erase(iter);
            } else {
                ++iter;
            }
        }
    }


}