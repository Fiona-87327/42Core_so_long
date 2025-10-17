/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:29:45 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/26 20:26:35 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows && map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

static void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_wall)
			mlx_delete_image(game->mlx, game->img_wall);
		if (game->img_floor)
			mlx_delete_image(game->mlx, game->img_floor);
		if (game->img_player_r)
			mlx_delete_image(game->mlx, game->img_player_r);
		if (game->img_player_l)
			mlx_delete_image(game->mlx, game->img_player_l);
		if (game->img_collect)
			mlx_delete_image(game->mlx, game->img_collect);
		if (game->img_exit)
			mlx_delete_image(game->mlx, game->img_exit);
	}
}

void	cleanup_game(t_game *game)
{
	free_mlx(game);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	error_exit(const char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
