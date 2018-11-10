#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "display.h"
#include "map.h"

//#include "entity.h"

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
    //SDL_DestroyWindow(display->window);
    //SDL_DestroyRenderer(display->renderer);
}


void display_blk(struct display *display, enum blocktype blocktype, int x, int y)
{
    if(blocktype != BLOCK)
        return;

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

/*
void display_entity(struct display *display, struct entity *entity)
{

    SDL_Texture *texture = display->ent_textures[entity->type];
    SDL_Renderer *renderer = display->renderer;

    SDL_Rect texr =
    {
        .x = entity->pos.x,
        .y = entity->pos.y,
        .w = entity->size.w,
        .h = entity->size.h,
    };

    SDL_QueryTexture(texture, NULL, NULL, &entity->pos.x, &entity->pos.y);
    SDL_RenderCopy(renderer, texture, NULL, &texr);
}
*/
/*
void render_frame(struct GameContext game)
{
    struct display *display = game.display;

    SDL_RenderClear(display->renderer);

    for(int y = 0; y < game.map->height; y++)
    {
        for(int x = 0; x < game.map->width; x++)
        {
            enum blocktype blocktype = game.map->block[y * game.map->width + x];
            display_blk(display, blocktype, x * BLOCK_SIZE, y * BLOCK_SIZE);
        }
    }

    for(int entity_i = 0; entity_i < game.map->nbEntities; entity_i++)
    {
        struct entity entity = game.map->entities[entity_i];
        display_entity(display, entity);
    }

    SDL_RenderPresent(display->renderer);
}
*/

void load_textures(struct display *display, char *textures_path)
{
    display->blk_textures = malloc(sizeof(SDL_Texture*) * 1);
//    display->blk_textures[0] = IMG_LoadTexture(display->renderer, "maps/lvl1_textures/block.png");
    return;
}

void display_map(struct display *display, struct map *map)
{
    SDL_RenderClear(display->renderer);

    for(int y = 0; y < map->height; y++)
    {
        for(int x = 0; x < map->width; x++)
        {
            enum blocktype blocktype = map->block[y * map->width + x];
            display_blk(display, blocktype, x * BLOCK_SIZE, y * BLOCK_SIZE);
        }
    }

    SDL_RenderPresent(display->renderer);
}
