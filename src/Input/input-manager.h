#pragma once
#include <SDL2/SDL.h>
#include <unordered_map>

class InputManager {
public:
    void update();
    bool isKeyPressed(SDL_Scancode key) const;
    bool isKeyDown(SDL_Scancode key) const;
    bool isKeyReleased(SDL_Scancode key) const;

private:
    std::unordered_map<SDL_Scancode, bool> keyState;
    std::unordered_map<SDL_Scancode, bool> prevKeyState;
};
