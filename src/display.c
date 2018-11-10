struct display init_display(int width, int height)
{
    struct display display;

    display.window = SDL_CreateWindow("Rush Coke", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * BLOCK_SIZE, height * BLOCK_SIZE, SDL_WINDOW_SHOWN);
    display.renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    return display;
}

void end_display(struct display display)
{
    SDL_DestroyWindow(display.window);
    SDL_DestroyRenderer(display.renderer);
}


void display_blk(struct display display, enum blocktype blocktype, int x, int y)
{
    SDL_Texture *texture = display.blk_textures[blocktype];
    SDL_Renderer *renderer = display.renderer;

    SDL_Rect texr =
    {
        .x = x,
        .y = y,
        .w = BLOCK_SIZE,
        .h = BLOCK_SIZE,
    }

    SDL_QueryTexture(texture, NULL, NULL, x, y);
    SDL_RenderCopy(renderer, texture, NULL, &texr);
}

void display_entity(struct display display, struct entity entity)
{

    SDL_Texture *texture = display.ent_textures[entity.type];
    SDL_Renderer *renderer = display.renderer;

    SDL_Rect texr =
    {
        .x = entity.pos.x,
        .y = entity.pos.y,
        .w = entity.size.w,
        .h = entity.size.h,
    }

    SDL_QueryTexture(texture, NULL, NULL, x, y);
    SDL_RenderCopy(renderer, texture, NULL, &texr);
}

void render_frame(struct GameContext game)
{
    struct display display = game.dislay;

    SDL_RenderClear(display.renderer);

    for(int y = 0; y < game.map.height; y++)
    {
        for(int x = 0; x < game.map.width; x++)
        {
            enum blocktype blocktype = game.block[y * game.map.width + x];
            display_blk(display, x * BLOCK_SIZE, y * BLOCK_SIZE, display.blk_textures[blocktype]);
        }
    }

    for(int entity_i = 0; entity_i < game.map.nbEntities; entity_i++)
    {
        struct entity entity = game.map.entity[entity_i];
        display_entity(display, entity);
    }

    SDL_RenderPresent(display.renderer);
}
