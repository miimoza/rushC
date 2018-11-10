#include "map.h"

int get_width(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    int count = 0;
    char c;
    for (c = fgetc(file); c != '\n'; c = fgetc(file))
    {
        count++;
    }
    fclose(file);
    return count;
}

int get_height(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    int count = 0;
    char c;
    for (c = fgetc(file); c != EOF; c = fgetc(file))
    {
        if (c == '\n')
            count++;
    }
    fclose(file);
    return count;
}

struct map parse_map(char *path)
{
    struct map map;
    map.width = get_width(path);
    map.height = get_height(path);
    int size = map.width * map.height;
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

char *parse(char **path, int size)
{
    char *array_map = malloc(size * sizeof(char *));
    int i = 0;
    for (; path[i]; i++)
    {
        array_map[i] = *path[i];
    }
    return array_map;

}
