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

int get_pos_x(char *path, char chr)
{
    FILE *file;
    file = fopen(path, "r");
    int count;
    char c;
    for (c = fgetc(file); c != chr; c = fgetc(file))
    {
        count++;
    }
    fclose(file);
    return count;
}

int get_pos_y(char *path, char chr)
{
    FILE *file;
    file = fopen(path, "r");
    int count;
    char c;
    for (c = fgetc(file); c != chr; c = fgetc(file))
    {
        if (c == '\n')
            count++;
    }
    fclose(file);
    return count;
}

int get_entitynb(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    int count = 0;
    char c;
    for (c = fgetc(file); c != EOF; c = fgetc(file))
    {
        if (c == 'p' || 'e' || 'g')
            count++;
    }
    fclose(file);
    return count;
}

struct map *parse_map(char *path, char *texture_path)
{
    struct map *map = malloc(sizeof(struct map));
    map->nbentities = 0;
    map->entities = malloc(get_entitynb(path) * sizeof(struct entity));
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
            map->block[i] = DBLOCK;
        else if (c == 'p')
        {
            map->entities[map->nbentities++] = create_entity(PLAYER);
        }
        else if (c == 'e')
        {
            map->entities[map->nbentities++] = create_entity(ENEMY);
        }
        else if (c == 'g')
        {
            map->entities[map->nbentities++] = create_entity(GUN_PICKUP);
        }
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

enum blocktype get_block(struct map *map, struct vector2 vec)
{
    return map->block[fti(vec.x + 0.5f) + fti(vec.y) * map->width];
}

struct entity create_entity(enum entitytype)
{
    struct entity *player =
    {
        entitytype,
        struct vector2 vec_pos =
        {
            get_pos_x(char *path, c),
            get_pos_y(char *path, c)
        }
        struct vector2 vec_spd =
        {
            0,
            0
        };
        struct vector2 vec_acc =
        {
            0,
            0
        }
    };
    return player;
}
