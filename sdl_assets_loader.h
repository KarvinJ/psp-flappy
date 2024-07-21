#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

typedef struct
{
    SDL_Texture *texture;
    SDL_Rect textureBounds;
} Sprite;

Sprite loadSprite(SDL_Renderer *renderer, const char *file, int positionX, int positionY);

Mix_Chunk *loadSound(const char *p_filePath);