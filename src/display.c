#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"
#include "display.h"

struct display *init_display(int width, int height)
{
    struct display *display = malloc(sizeof(struct display));

    display->window = SDL_CreateWindow("Rush Coke", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * BLOCK_SIZE, height * BLOCK_SIZE, SDL_WINDOW_SHOWN);
    display->renderer = SDL_CreateRenderer(display->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    display->blk_textures = NULL;
    display->ent_textures = NULL;
    return display;
}

void end_display(struct display *display)
{
    SDL_DestroyWindow(display->window);
    SDL_DestroyRenderer(display->renderer);
}


void display_blk(struct display *display, enum blocktype blocktype, int x, int y)
{

    SDL_Texture *texture = display->blk_textures[blocktype];
    SDL_Renderer *renderer = display->renderer;

    SDL_Rect texr =
    {
        .x = x,
        .y = y,
        .w = BLOCK_SIZE,
        .h = BLOCK_SIZE,
    };

    SDL_QueryTexture(texture, NULL, NULL, &x, &y);
    SDL_RenderCopy(renderer, texture, NULL, &texr);
}


void display_entity(struct display *display, struct entity entity)
{

    SDL_Texture *texture = display->ent_textures[entity.type];
    SDL_Renderer *renderer = display->renderer;

    float fposx =  entity.pos.x * BLOCK_SIZE;
    float fposy =  entity.pos.y * BLOCK_SIZE;
    int posx = fposx;
    int posy = fposy;
    SDL_Rect texr =
    {
        .x = posx,
        .y = posy,
        .w = BLOCK_SIZE,
        .h = BLOCK_SIZE,
    };

    SDL_QueryTexture(texture, NULL, NULL, &posx, &posy);
    SDL_RenderCopy(renderer, texture, NULL, &texr);
}


void load_blk_texture(struct display *display, enum blocktype blk_type, char *textures_path)
{
    char buffer[4096];
    strcpy(buffer, textures_path);

    switch (blk_type) {
        case BLOCK:
            strcat(buffer, "block.png");
            break;
        case AIR:
            return;
        case SPIKE:
            strcat(buffer, "spike.png");
            break;
        case DBLOCK:
            strcat(buffer, "destructible_block.png");
            break;
    }

    display->blk_textures[blk_type] = IMG_LoadTexture(display->renderer, buffer);
}

void load_ent_texture(struct display *display, enum entitytype ent_type, char *textures_path)
{
    char buffer[4096];
    strcpy(buffer, textures_path);

    switch (ent_type) {
        case PLAYER:
            strcat(buffer, "player.png");
            break;
        case ENEMY:
            strcat(buffer, "enemy.png");
            break;
        case BULLET:
            strcat(buffer, "bullet.png");
            break;
        case GUN_PICKUP:
            strcat(buffer, "gun_pickup.png");
            break;
        case DOUBLE_JUMP_PICKUP:
            strcat(buffer, "double_jump_pickup.png");
            break;
    }

    display->ent_textures[ent_type] = IMG_LoadTexture(display->renderer, buffer);
}

void load_background(struct display *display, char *textures_path)
{
    char buffer[4096];
    strcpy(buffer, textures_path);
    strcat(buffer, "background.png");
    display->background = IMG_LoadTexture(display->renderer, buffer);
}

void load_textures(struct display *display, char *textures_path)
{
    display->blk_textures = malloc(sizeof(SDL_Texture*) * NB_BLK_TYPES);
    display->ent_textures = malloc(sizeof(SDL_Texture*) * NB_ENT_TYPES);

    load_background(display, textures_path);

    load_blk_texture(display, BLOCK, textures_path);
    load_blk_texture(display, SPIKE, textures_path);
    load_blk_texture(display, DBLOCK, textures_path);

    load_ent_texture(display, PLAYER, textures_path);
    load_ent_texture(display, ENEMY, textures_path);
    load_ent_texture(display, BULLET, textures_path);
    load_ent_texture(display, GUN_PICKUP, textures_path);
    load_ent_texture(display, DOUBLE_JUMP_PICKUP, textures_path);

    return;
}

void display_background(SDL_Renderer *renderer, SDL_Texture *background, int width, int height)
{

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int posx = x * BLOCK_SIZE;
            int posy = y * BLOCK_SIZE;
            SDL_Rect texr =
            {
                .x = posx,
                .y = posy,
                .w = BLOCK_SIZE,
                .h = BLOCK_SIZE
            };


            SDL_QueryTexture(background, NULL, NULL, &posx, &posy);
            SDL_RenderCopy(renderer, background, NULL, &texr);
        }
    }
}
void display_coke_bar(SDL_Renderer *renderer, int coke)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect =
    {
        .x = 8,
        .y = 8,
        .w = coke,
        .h = 10
    };

    SDL_RenderFillRect(renderer, &rect);

}

void display_map(struct display *display, struct map *map)
{
    SDL_RenderClear(display->renderer);
    display_background(display->renderer, display->background, map->width, map->height);
    for(int y = 0; y < map->height; y++)
    {
        for(int x = 0; x < map->width; x++)
        {
            enum blocktype blocktype = map->block[y * map->width + x];
            display_blk(display, blocktype, x * BLOCK_SIZE, y * BLOCK_SIZE);
        }
    }

    for(int entity_i = 0; entity_i < map->nbentities; entity_i++)
    {
        struct entity entity = map->entities[entity_i];
        //printf("entity : x: %f y: %f\n", entity.pos.x, entity.pos.y);
        display_entity(display, entity);
    }
    display_coke_bar(display->renderer, 250);

    SDL_RenderPresent(display->renderer);
}
