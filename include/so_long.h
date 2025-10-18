/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:55:19 by jiyawang          #+#    #+#             */
/*   Updated: 2025/10/18 11:14:03 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_ESC 65307

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_map
{
	char		**grid;
	int			rows;
	int			cols;
	int			n_player;
	int			n_exit;
	int			n_collect;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	int			player_x;
	int			player_y;
	int			move_count;
	int			collected;
	int			player_dir;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player_r;
	mlx_image_t	*img_player_l;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;
}				t_game;

int				validate_map(t_map *map);
void			free_map(t_map *map);
void			cleanup_game(t_game *game);
void			error_exit(const char *msg);
int				load_textures(t_game *game);
int				init_game(t_game *game, const char *map_file);
void			key_handler(mlx_key_data_t keydata, void *param);
t_map			*parse_map(const char *filename);
void			render_tile(t_game *game, int x, int y);
void			render_game(t_game *game);
void			move_update(t_game *game, int new_x, int new_y);
int				move_player(t_game *game, int new_x, int new_y);
int				main(int argc, char **argv);
char			*read_file_content(const char *filename);
void			count_map_elements(t_map *map);
int				check_path(t_map *map);
int				check_valid_chars(t_map *map);
int				validate_file_extension(const char *filename);

#endif
