#ifndef MAP_H_
#define MAP_H_

#include "stdio.h"
#include <stdlib.h>

enum blocktype
{
    AIR,
    BLOCK,
    SPIKE,
    DESTRUCTIBLE_BLOCK
};

struct map
{
    char *texture_path;
    int width;
    int height;
    int nbentities;
    //struct entity *entities
    enum blocktype *block;
};

struct map *parse_map(char *path, char *texture_path);
int get_width(char *path);
int get_height(char *path);
struct map **parse_maps(char **path, int size, char **texture_path);

#endif /* !MAP_H_ */
