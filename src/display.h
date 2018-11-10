#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "map.h"
//#include "entity.h"

#define BLOCK_SIZE 16

struct display
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture **blk_textures;
    SDL_Texture **ent_textures;
    SDL_Texture *background;
};

struct display *init_display(int width, int height);
void end_display(struct display *display);
//void render_frame(struct GameContext game);
void display_map(struct display *display, struct map *map);
void load_textures(struct display *display, char *textures_path);

#endif /* !DISPLAY_H_ */
