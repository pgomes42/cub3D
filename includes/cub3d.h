/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:06 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/27 12:11:06 by pgomes           ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>
# define W_WIDTH 1080
# define W_HEIGHT 900
# define TILE_SIZE 64
# define MOVESPEED 0.05
# define ROTSPEED 0.05


typedef struct s_map
{
    char    **map;
    char    **aux_map;
    char	**minimalist;
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    char    *floor_color;
    char    *ceiling_color;
    int		height;
    int		width;
}				t_map;

typedef struct s_player
{
   
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
    int		move_speed;
    int		rot_speed;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

typedef struct s_raycast
{
    double	camera_x;
	double	dir_x;
	double	dir_y;
    double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
    
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
    
} t_raycst;

typedef struct s_texture
{
    void		*img;
    char		    *addr;
    int		    pixel_bits;
    int		    size_line;
    int		    endian;
    int		    width;
    int		    height;
    int         tex_x;
    int         tex_y;
    
    
} t_texture;

typedef struct s_game
{
    
    void	*mlx;
    void	*win;
    int    floor_color;
    int     ceiling_color;
    t_texture    n_wall;
    t_texture    s_wall;
    t_texture    e_wall;
    t_texture    w_wall;
    int         width;
    int         height;
    int         line_height;
    t_raycst	*ray;
    t_texture	image;
    t_map	    *map;
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
int	key_press_handler(int key, t_game *game);
int	move_player(t_game *data);
int	validate_move(t_game *data, double new_x, double new_y);
void	init_player_direction(t_player *player);
int	raycasting( t_game *data);
int ft_draw(t_game *data);
int init_windows(t_game *game);
int get_texture_pixel(t_texture *tex, int x, int y);
int init_textures(t_game *game);
void put_pixel_to_image(t_texture *data, int x, int y, int color);
void update_texture_pixels(t_game *game, t_raycst *ray, int x);

#endif