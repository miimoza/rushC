#ifndef MAP_H_
#define MAP_H_

#include "stdio.h"
#include "vector2.h"
#include "entity.h"
#include <stdlib.h>

#define NB_BLK_TYPES 4

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
    enum blocktype *block;
};

struct map *parse_map(char *path, char *texture_path);
int get_width(char *path);
int get_height(char *path);
int get_entitynb(char *path);
int get_pos_x(char *path, char chr);
int get_pos_y(char *path, char chr);
struct map **parse_maps(char **path, int size, char **texture_path);
int fti(float x);
enum blocktype get_block(struct map *map, struct vector2 vec);

#endif /* !MAP_H_ */
