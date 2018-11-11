#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"


struct display *init_display(int width, int height);
void end_display(struct display *display);
//void render_frame(struct GameContext game);
void display_map(struct display *display, struct map *map);
void load_textures(struct display *display, char *textures_path);
void display_menu(SDL_Renderer *renderer);

#endif /* !DISPLAY_H_ */
