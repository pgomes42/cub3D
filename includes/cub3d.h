/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:06 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/12 10:06:17 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/header/libft.h"
# define W_WIDTH 1080
# define W_HEIGHT 900
# define TILE_SIZE 65


typedef struct s_map
{
    char    **map;
    char    **reverter_map;
    char	**minimalist;
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    char    *floor_color;
    char    *ceiling_color;
    int		map_height;
    int		map_rev_height;
}				t_map;

typedef struct s_player
{
    double	pos_x;
    double	pos_y;
    double	dir_x;
    double	dir_y;
    double	plane;
}				t_player;

typedef struct s_raycast
{
    int		wall_height;
    
} t_raycst;

typedef struct s_image
{
    void		*img;
    char		*addr;
    int		    pixel_bits;
    int		    size_line;
    int		    endian;
    
} t_image;

typedef struct s_game
{
    
    void	*mlx;
    void	*win;
    void    *floor;
    void    *n_wall;
    void    *s_wall;
    void    *e_wall;
    void    *w_wall;
    int     width;
    int     height;
    t_image	*image;
    t_map	*map;
    t_player	*player;
}				t_game;

int event_key(int keycode, t_game *game);
int    ft_clean_game(t_game *game);
void    ft_clean_map(t_map *map);
void    init_args(t_game *game, char *file);
int     ft_line_empty(char *line);
int     ft_isplayer(char c);
int     init_windows(t_game *game);
int     ft_isargs_valid(char *line);
int     validate_map(t_game *game);
void    ft_clean_matrix(char **matrix);
int    traspost_matriz(t_map *map);
int     ft_iscolor_valid(char *color);
void    print_map(t_map *map, char **min);
int     init_textures(t_game *game);
void    ft_init_player(t_game *game);
int    ft_get_color(char *color);

int init_textures(t_game *game);
void put_pixel_to_image(t_game *data, int x, int y, int color);

#endif