#ifndef DISPLAY_H_
#define DISPLAY_H_


#define BLOCK_SIZE 32

struct display
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture **blk_textures;
};

struct display init_display(int width, int height);
void end_display(struct display display);
void render_frame(struct GameContext game);

#endif /* !DISPLAY_H_ */
