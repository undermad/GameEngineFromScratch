#pragma once

#include <string>

std::string GetResourceDir() {
#ifdef NDEBUG //release build
    return "assets/";
#else
    return "D:/Programming/C++/GameEngineFromScratch/Game/assets/";
#endif
};
