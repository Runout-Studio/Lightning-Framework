#include <SDL2/SDL.h>
#include <iostream>
#include "Input/input-manager.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Lightning Input Test",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    InputManager input;
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        input.update();

        // Example: Close window with ESC
        if (input.isKeyPressed(SDL_SCANCODE_ESCAPE))
            running = false;

        // Detect F1–F12
        for (int i = SDL_SCANCODE_F1; i <= SDL_SCANCODE_F12; ++i) {
            if (input.isKeyPressed((SDL_Scancode)i)) {
                std::cout << "Pressed F" << (i - SDL_SCANCODE_F1 + 1) << std::endl;
            }
        }

        // Detect arrows
        if (input.isKeyPressed(SDL_SCANCODE_UP)) std::cout << "Up pressed\n";
        if (input.isKeyPressed(SDL_SCANCODE_DOWN)) std::cout << "Down pressed\n";
        if (input.isKeyPressed(SDL_SCANCODE_LEFT)) std::cout << "Left pressed\n";
        if (input.isKeyPressed(SDL_SCANCODE_RIGHT)) std::cout << "Right pressed\n";

        SDL_Delay(16); // Simulate ~60fps
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
