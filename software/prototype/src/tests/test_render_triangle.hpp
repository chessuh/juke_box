#pragma once

#include <SDL3/SDL.h>
#include <cmath>

#include "../globals.hpp"

namespace Tests {
    void test_render_triangle(SDL_Renderer* renderer, uint64_t start_ticks) {
        static SDL_Texture* canvas = nullptr;
        if (!canvas) {
            canvas = SDL_CreateTexture(renderer,
                                       SDL_PIXELFORMAT_RGBA8888,
                                       SDL_TEXTUREACCESS_TARGET,
                                       SCREEN_WIDTH,
                                       SCREEN_HEIGHT);
            SDL_SetTextureScaleMode(canvas, SDL_SCALEMODE_NEAREST);
        }

        double t = (SDL_GetTicks() - start_ticks) / 1000.0;
        double angle = t * 1.5;
        float cx = SCREEN_WIDTH / 2.0f;
        float cy = SCREEN_HEIGHT / 2.0f;
        float r = 22.0f;                                
        SDL_Vertex v[3];
        for (int i = 0; i < 3; i++) {
            double a = angle + i * (2.0 * SDL_PI_D / 3.0);
            v[i].position.x = cx + (float)cos(a) * r;
            v[i].position.y = cy + (float)sin(a) * r;
            v[i].color = { 255, 255, 255, 255 };
            v[i].tex_coord = { 0, 0 };
        }

        SDL_SetRenderTarget(renderer, canvas);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderGeometry(renderer, nullptr, v, 3, nullptr, 0);

        SDL_SetRenderTarget(renderer, nullptr);
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, canvas, nullptr, nullptr);

        SDL_RenderPresent(renderer);
    }
}