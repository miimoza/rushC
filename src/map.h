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
    int weight;
    int height;
    enum blocktype *block;
};

struct map parse_map(char *path);
int get_size(char *path);

#endif /* !MAP_H_ */
