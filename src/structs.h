#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define NUMBER_KEYS 5
#define BLOCK_SIZE 32
#define NB_ENT_TYPES 5
#define NB_BLK_TYPES 4

struct vector2
{
    float x;
    float y;
};


struct display
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture **blk_textures;
    SDL_Texture **ent_textures;
    SDL_Texture *background;
};

enum entitytype
{
    PLAYER,
    ENEMY,
    BULLET,
    GUN_PICKUP,
    DOUBLE_JUMP_PICKUP
};

enum direction
{
    DIR_LEFT,
    DIR_RIGHT
};

struct entity
{
    enum entitytype type;
    struct vector2 pos;
    struct vector2 spd;
    struct vector2 acc;
    enum direction dir;
};



struct input
{
    int inputs[NUMBER_KEYS];
};

enum keys
{
    QUIT,
    SPACE,
    LEFT,
    RIGHT,
    SHOOT
};

enum blocktype
{
    AIR,
    BLOCK,
    SPIKE,
    DBLOCK
};

struct map
{
    char *texture_path;
    int width;
    int height;
    int nbentities;
    struct entity *entities;
    struct entity player;
    enum blocktype *block;
};

struct GameContext
{
    struct map **maps;
    struct map *map;
    int is_playing;
    int nb_maps;
    int cur_map;
};

#endif /* !STRUCTS_H_ */
