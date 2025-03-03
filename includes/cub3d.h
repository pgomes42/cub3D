/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:06 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 11:25:10 by pgomes           ###   ########.fr       */
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


# define PI 3.14159265359
# define P2 1.57079632679 // PI/2
# define P3 4.71238898038 //3*PI/2

# define FOV 1.04719755 //(PI / 3)

# define TEXTURE_H 64
# define TEXTURE_Y 64

# define WIDTH 1920
# define HEIGHT 1080

# define SQUARE 64
# define PLAYER_SIZE 20
# define OBSTACLE_COLOR 0x000000

# define DR 0.000545415

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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
   
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
    double player_delta_y;
    double	player_delta_x;
	double	plane_x;
	double	plane_y;
    double  player_angle;
	int		has_moved;
    int		move_speed;
    int		rot_speed;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;
typedef struct s_intersection
{
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	tan;
}	t_intersection;
typedef struct s_raycast
{
    
	int		r;
	float	ra;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	ray_h;
	float	ray_v;
	float	wall_x;
	float	line;
	float	line_h;
	float	line_v;
    
} t_raycst;

typedef struct s_texture
{
    void		*img;
    char		    *addr;
    int             id;
    int		    pixel_bits;
    int		    size_line;
    int		    endian;
    int		    size;
    int         tex_x;
    int         tex_y;
    double       pos;
    double	step;
    
    
} t_texture;

typedef struct s_texture_vars
{
	int		y;
	float	ty;
	float	tx;
	float	ty_step;
	float	ty_offset;
}	t_texture_vars;

typedef struct s_game
{
    
    void	*mlx;
    void	*win;
    int    floor_color;
    int     ceiling_color;
    char        texture_nbr;
    t_texture    n_wall;
    t_texture    s_wall;
    t_texture    e_wall;
    t_texture    w_wall;
    t_img       img;
    
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
double ft_init_player(t_game *game);
int    ft_get_color(char *color);
int	key_press_handler(int key, t_game *game);
int	move_player(t_game *data);
//int	validate_move(t_game *data, double new_x, double new_y);
void	init_player_direction(t_player *player);
void	raycaster(t_game *data);
int ft_draw(t_game *data);
int init_windows(t_game *game);
int get_texture_pixel(t_texture *tex, int x, int y);
int init_textures(t_game *game);
void put_pixel_to_image(t_img *data, int x, int y, int color);
void update_texture_pixels(t_game *game, t_raycst *ray, int x);
int	move_player(t_game *data);
void	ft_value_setter(float *val1, float *set1, float *val2, float *set2);
void	ft_set_tex(t_game *win, float ray_point, char c);
void	ft_init_vars(t_raycst	*vars, t_game *win);
int	ft_circle_normalizer(float *ra);
float	line_length(float x1, float y1, float x2, float y2);
void	draw_3d_walls(t_game *win, float distance, int column, float hx);
void	ft_rotate_left(t_game *mlx);
void	ft_rotate_right(t_game *mlx);
int	arrow_keys(int Key, t_game *mlx);

#endif