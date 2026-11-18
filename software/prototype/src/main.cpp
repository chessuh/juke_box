#include <iostream>
#include <SDL3/SDL.h>
#include <alsa/asoundlib.h>

#include "globals.hpp"

int main() {
    // TODO: deal with ALSA stuff later
    //snd_pcm_t* pcm_handle = nullptr;
    //int error = snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK);

    SDL_SetHintWithPriority(SDL_HINT_KMSDRM_REQUIRE_DRM_MASTER, "1", SDL_HINT_DEFAULT);
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) { 
        SDL_Log("Failed to initialized SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_WindowFlags window_flags = SDL_WINDOW_FULLSCREEN 
                                |  SDL_WINDOW_BORDERLESS;
    SDL_Window* window = SDL_CreateWindow("juke_box", SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    SDL_SetRenderLogicalPresentation(renderer,
                                     SCREEN_WIDTH,
                                     SCREEN_HEIGHT,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            } else if (event.type == SDL_EVENT_KEY_DOWN) {
                SDL_Keycode keycode = event.key.key;
                if (keycode == SDLK_Q) {
                    running = false;
                }
            }
        }
    } 

    return SDL_APP_SUCCESS;
}