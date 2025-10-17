/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:27:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/26 14:57:50 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long map_file.ber\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(t_game));
	if (!init_game(game, argv[1]))
	{
		cleanup_game(game);
		ft_printf("Error\nFailed to initialize game!\n");
		free(game);
		return (1);
	}
	mlx_loop(game->mlx);
	cleanup_game(game);
	free(game);
	return (0);
}
