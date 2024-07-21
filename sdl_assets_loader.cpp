#include "sdl_assets_loader.h"

Sprite loadSprite(SDL_Renderer *renderer, const char *file, int positionX, int positionY)
{
    SDL_Rect textureBounds = {positionX, positionY, 0, 0};

    SDL_Texture *texture = IMG_LoadTexture(renderer, file);

    if (texture != nullptr)
    {
        SDL_QueryTexture(texture, NULL, NULL, &textureBounds.w, &textureBounds.h);
    }

    Sprite sprite = {texture, textureBounds}; 

    return sprite;
}

Mix_Chunk *loadSound(const char *p_filePath)
{
    Mix_Chunk *sound = nullptr;

    sound = Mix_LoadWAV(p_filePath);
    if (sound == nullptr)
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }

    return sound;
}