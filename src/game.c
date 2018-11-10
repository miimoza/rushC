struct GameContext init_game()
{
    struct GameContext game;
    game.map_index = 0
    game.maps = parse_maps();
    game.map = game.maps[game.map_index];
    game.display = init_display();
    game.display = load_textures(map.texture_path);
    return game;
}

void end_game(struct GameContext game)
{
     end_display(game.dislay);
}
