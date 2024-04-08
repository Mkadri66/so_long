#include "so_long.h"

void	display_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,game->mlx_win_pointer, game->player, width * 50, height * 50);
	game->y = height;
	game->x = width;
}

void	display_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,game->mlx_win_pointer, game->collectables, width * 50, height * 50);
	game->collectable_count++;
}

void	set_images_in_map(t_game *game)
{
	int	i;
	int	j;
	game->floor = NULL;
	game->walls = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->collectables = NULL;
	game->x = 0;
	game->y = 0;
	game->floor = mlx_xpm_file_to_image(game->mlx_pointer,"images/floor.xpm", &i, &j);
	game->walls = mlx_xpm_file_to_image(game->mlx_pointer,"images/walls.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_pointer,"images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_pointer,"images/exit.xpm", &i, &j);
	game->collectables = mlx_xpm_file_to_image(game->mlx_pointer,"images/collectables.xpm", &i, &j);
}

void display_sprites(t_game *game)
{
    int height;
    int width;

    game->collectable_count = 0;
    height = 0;
    while (height < game->map_height)
    {
        width = 0;
        while (game->map[height][width])
        {
            if (game->map[height][width] == '1')
                mlx_put_image_to_window(game->mlx_pointer,game->mlx_win_pointer, game->walls, width * 50, height * 50);
            if (game->map[height][width] == '0')
                mlx_put_image_to_window(game->mlx_pointer,game->mlx_win_pointer, game->floor, width * 50, height * 50);
            if (game->map[height][width] == 'C')
                display_collectable(game, height, width);
            if (game->map[height][width] == 'P')
                display_player(game, height, width);
            if (game->map[height][width] == 'E')
                mlx_put_image_to_window(game->mlx_pointer,game->mlx_win_pointer, game->exit, width * 50, height * 50);
            width++;
        }
        height++;
    }
}

void    game_init(t_game *game)
{
    game->mlx_pointer = mlx_init();
    game->mlx_win_pointer = mlx_new_window(game->mlx_pointer, (game->map_width * 50), (game->map_height * 50), "So_Long");
    set_images_in_map(game);
    display_sprites(game);
    game->movement = 0;
    //print_game_info(game);
}
