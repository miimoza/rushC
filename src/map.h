#ifndef MAP_H_
#define MAP_H_

#include "stdio.h"
#include "entity.h"
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
    struct entity *entities
    enum blocktype *block;
};

struct map *parse_map(char *path);
int getwidth(char *path);
int getheight(char *path);
struct map **parse_maps(char *path);

#endif /* !MAP_H_ */
