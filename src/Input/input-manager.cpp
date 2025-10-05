#include "input-manager.h"

void InputManager::update() {
    prevKeyState = keyState;

    const Uint8* current = SDL_GetKeyboardState(nullptr);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        keyState[(SDL_Scancode)i] = current[i];
    }
}

bool InputManager::isKeyPressed(SDL_Scancode key) const {
    return keyState.at(key) && !prevKeyState.at(key);
}

bool InputManager::isKeyDown(SDL_Scancode key) const {
    return keyState.at(key);
}

bool InputManager::isKeyReleased(SDL_Scancode key) const {
    return !keyState.at(key) && prevKeyState.at(key);
}
