#include "map.h"

struct map parse_map(char *path)
{
    struct map map;
    map.block = malloc(map.weight * map.height * sizeof(char));
    FILE *file;
    file = fopen(path, "r");
    char c;
    int i = 0;
    for (c = fgetc(file); c != EOF; c = fgetc(file), i++)
    {
        if (c == '\n')
            c = fgetc(file);
        if (c == 'b')
            map.block[i] = BLOCK;
        else if (c == 's')
            map.block[i] = SPIKE;
        else if (c == 'd')
            map.block[i] = DESTRUCTIBLE_BLOCK;
        else
            map.block[i] = AIR;
    }
    i++;
    map.block[i] = '\0';
    return map;
}
