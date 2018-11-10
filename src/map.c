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

struct map *parse_map(char *path, char *texture_path)
{
    struct map *map = malloc(sizeof(struct map));
    printf("spr\n");
    map->width = get_width(path);
    printf("width: %d\n", map->width);
    map->height = get_height(path);
    printf("height: %d\n", map->height);
    map->texture_path = texture_path;
    int size = map->width * map->height;
    map->block = malloc(size * sizeof(enum blocktype));
    FILE *file;
    file = fopen(path, "r");
    char c;
    int i = 0;
    for (c = fgetc(file); c != EOF; c = fgetc(file), i++)
    {
        printf("BOUCLE\n");
        if (c == '\n')
            c = fgetc(file);
        if (c == 'b')
            map->block[i] = BLOCK;
        else if (c == 's')
            map->block[i] = SPIKE;
        else if (c == 'd')
            map->block[i] = DESTRUCTIBLE_BLOCK;
        else
            map->block[i] = AIR;
    }
    fclose(file);
    return map;
}

struct map **parse_maps(char **path, int size, char **texture_path)
{
    struct map **array_map = malloc(size * sizeof(char *));
    int i = 0;
    for (; path[i]; i++)
    {
        array_map[i] = parse_map(path[i], texture_path[i]);
    }
    return array_map;

}

int fti(float x)
{
    return x;
}

enum blocktype get_block(struct map *map, struct vector2 *vec)
{
    return map->block[fti(vec->x) + fti(vec->y) * map->width];
}
