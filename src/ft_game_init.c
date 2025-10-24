/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:18:29 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/26 13:37:45 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (game->map->grid[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	init_images(t_game *game, mlx_texture_t **tex, mlx_image_t **img,
		const char *path)
{
	*tex = mlx_load_png(path);
	if (!*tex)
		return (0);
	*img = mlx_texture_to_image(game->mlx, *tex);
	mlx_delete_texture(*tex);
	return (*img != NULL);
}

int	load_textures(t_game *game)
{
	mlx_texture_t	*tex;

	if (!init_images(game, &tex, &game->img_wall, "./textures/wall.png"))
		return (0);
	if (!init_images(game, &tex, &game->img_floor, "./textures/floor.png"))
		return (0);
	if (!init_images(game, &tex, &game->img_collect,
			"./textures/collectible.png"))
		return (0);
	if (!init_images(game, &tex, &game->img_exit, "./textures/exit.png"))
		return (0);
	if (!init_images(game, &tex, &game->img_player_r, "./textures/playerr.png"))
		return (0);
	if (!init_images(game, &tex, &game->img_player_l, "./textures/playerl.png"))
		return (0);
	return (1);
}

int	init_game(t_game *game, const char *map_file)
{
	game->map = parse_map(map_file);
	if (!game->map || !validate_map(game->map))
		return (0);
	game->mlx = mlx_init(game->map->cols * TILE_SIZE, game->map->rows
			* TILE_SIZE, "so_long", true);
	if (!game->mlx || !load_textures(game))
	{
		cleanup_game(game);
		return (0);
	}
	game->move_count = 0;
	game->collected = 0;
	set_player_pos(game);
	mlx_key_hook(game->mlx, &key_handler, game);
	render_game(game);
	return (1);
}
