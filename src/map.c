#include "map.h"

struct map parse_map(char *path)
{
    struct map map;
    int size = get_size(path);
    map.block = malloc(size * sizeof(char));
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
    fclose(file);
    return map;
}

int get_size(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    int count = 0;
    char c;
    for (c = fgetc(file); c != EOF; c = fgetc(file))
    {
        count++;
    }
    fclose(file);
    return count;
}
