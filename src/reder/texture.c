/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:27 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 11:20:47 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    load_addr_texture(t_texture *tex, int id)
{
    tex->id = id;
    tex->size = TILE_SIZE;
    tex->addr = mlx_get_data_addr(tex->img, &tex->pixel_bits, &tex->size_line, &tex->endian);
}




int init_textures(t_game *game)
{
    int whidth;
    int height;
    
    game->s_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->so_texture, &whidth, &height);
    if (game->s_wall.img)
       load_addr_texture(&game->s_wall, 1);
    else
        return (printf("Error\nFalied to creat south wall\n"), 0);
    game->n_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->no_texture, &whidth, &height);
    if (game->n_wall.img)
        load_addr_texture(&game->n_wall, 2);
    else
        return (printf("Error\nFalied to creat north wall\n"), 0);
    game->e_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->ea_texture, &whidth, &height);
    if (game->e_wall.img)
        load_addr_texture(&game->e_wall, 3);
    else
        return (printf("Error\nFalied to creat east wall\n"), 0);
    game->w_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->we_texture, &whidth, &height);
    if (game->w_wall.img)
        load_addr_texture(&game->w_wall, 4);
    else
        return (printf("Error\nFalied to creat west wall\n"), 0);
    return (1);
}

static t_texture get_texture(t_game *game, float *tx)
{
    if (game->texture_nbr == 'N')
    {
        *tx = 63 - *tx;
        return (game->n_wall);
    }
    if (game->texture_nbr == 'S')
        return (game->s_wall);
    if (game->texture_nbr == 'E')
    {
        *tx = 63 - *tx;
        return (game->e_wall);
    }
    return (game->w_wall);
    
}
static void	ft_wall_limits(int *line_h, float *ty_offset)
{
	if (*line_h > HEIGHT)
	{
		*ty_offset = ((float)*line_h - HEIGHT) / 2;
		*line_h = HEIGHT;
	}
}

void	draw_3d_walls(t_game *win, float distance, int column, float hx)
{
	int				line_h;
	int				line_start;
	t_texture			texture_to_use;
	t_texture_vars	vars;

	line_h = (SQUARE * HEIGHT) / distance;
	vars.ty_step = 64 / (float)line_h;
	vars.ty_offset = 0;
	ft_wall_limits(&line_h, &vars.ty_offset);
	line_start = (HEIGHT / 2) - (line_h / 2);
	vars.y = -1;
	vars.ty = vars.ty_step * vars.ty_offset;
	vars.tx = (int)(hx) % 64;
    texture_to_use = get_texture(win, &vars.tx);
    //printf("\n\ntx: %f\n", vars.tx);
	while (++vars.y < line_h)
	{
		put_pixel_to_image(&win->img, column, line_start + vars.y,
			get_texture_pixel(&texture_to_use,
				((int)vars.tx) % SQUARE, (int)(vars.ty)));
		vars.ty += vars.ty_step;
	}
}