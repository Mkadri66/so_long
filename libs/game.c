#include "so_long.h"

void print_game_info(t_game *game)
{
    printf("===== Game Information =====\n");
    printf("fd: %d\n", game->fd);
    printf("map_width: %d\n", game->map_width);
    printf("map_height: %d\n", game->map_height);
    printf("player_count: %d\n", game->player_count);
    printf("collectable_count: %d\n", game->collectable_count);
    printf("exit_count: %d\n", game->exit_count);
    printf("x: %d\n", game->x);
    printf("y: %d\n", game->y);

    printf("mlx_pointer: %p\n", game->mlx_pointer);
    printf("mlx_win_pointer: %p\n", game->mlx_win_pointer);
    printf("player: %p\n", game->player);
    printf("floor: %p\n", game->floor);
    printf("collectables: %p\n", game->collectables);
    printf("walls: %p\n", game->walls);
    printf("exit: %p\n", game->exit);
}

void print_map(t_game *game)
{
    printf("===== Map =====\n");
    for (int i = 0; i < game->map_height; i++)
    {
        for (int j = 0; game->map[i][j]; j++)
        {
            printf("%c ", game->map[i][j]);
        }
        printf("\n");
    }
}

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
    //print_game_info(game);
}