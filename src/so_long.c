/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:27:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 10:35:17 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	check_ber_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		ft_printf("Error: Map file must have a .ber extension\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long map_file.ber\n");
		return (0);
	}
	check_ber_extension(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(t_game));
	if (!init_game(game, argv[1]))
	{
		cleanup_game(game);
		ft_printf("Error: Failed to initialize game!\n");
		free(game);
		return (1);
	}
	mlx_loop(game->mlx);
	cleanup_game(game);
	free(game);
	return (0);
}
