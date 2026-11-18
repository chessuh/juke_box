#pragma once

struct Colour {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a = UINT8_MAX;
};
static const Colour BG_COLOUR = {20, 20, 20};

static const uint32_t SCREEN_WIDTH = 128;
static const uint32_t SCREEN_HEIGHT = 64;