/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:27 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 11:37:57 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    load_addr_texture(t_texture *tex)
{
    tex->height = TILE_SIZE;
    tex->width = TILE_SIZE;
    tex->addr = (int *)mlx_get_data_addr(tex->img, &tex->pixel_bits, &tex->size_line, &tex->endian);
}

int init_textures(t_game *game)
{
    int whidth;
    int height;
    
    game->s_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->so_texture, &whidth, &height);
    if (game->s_wall.img)
       load_addr_texture(&game->s_wall);
    else
        return (printf("Error\nFalied to creat south wall\n"), 0);
    game->n_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->no_texture, &whidth, &height);
    if (game->n_wall.img)
        load_addr_texture(&game->n_wall);
    else
        return (printf("Error\nFalied to creat north wall\n"), 0);
    game->e_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->ea_texture, &whidth, &height);
    if (game->e_wall.img)
        load_addr_texture(&game->e_wall);
    else
        return (printf("Error\nFalied to creat east wall\n"), 0);
    game->w_wall.img = mlx_xpm_file_to_image(game->mlx, game->map->we_texture, &whidth, &height);
    if (game->w_wall.img)
        load_addr_texture(&game->w_wall);
    else
        return (printf("Error\nFalied to creat west wall\n"), 0);
    return (1);
}

t_texture *get_texture(t_game *game)
{
    if (game->ray->side == 0)
    { 
        if (game->ray->dir_x > 0) {
            return(&game->e_wall);
        } else {
            return(&game->w_wall);
        }
    }
    else
    { 
        if (game->ray->dir_y > 0) {
            return(&game->s_wall);
        } else {
            return(&game->n_wall);
        }
    }
    return (NULL);
}
void update_texture_pixels(t_game *game, t_raycst *ray, int x)
{
    t_texture   *tex;
    double      wall_x;
    int         y;
    int         color;
    
    tex =  get_texture(game);
        
    if (ray->side == 0)
        wall_x = game->player->dir_y + ray->wall_dist * ray->dir_y;
    else
        wall_x = game->player->dir_x + ray->wall_dist * ray->dir_x;
    wall_x -= floor(wall_x);
    tex->tex_x = (int)(wall_x * (double)tex->width);
    if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
    tex->tex_x = tex->width - tex->tex_x - 1;
    y = ray->draw_start - 1;
    while (++y < ray->draw_end)
    {
        tex->tex_y = (y * 2 - W_HEIGHT + ray->line_height) * (tex->height / 2) / ray->line_height;
        color = get_texture_pixel(tex, tex->tex_x, tex->tex_y);
        put_pixel_to_image(tex, x, y, color);
    }
}
