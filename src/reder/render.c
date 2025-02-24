/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:45 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/12 10:06:48 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void render(t_game *data) 
{
    int x;
    int y;
    
    data->width = W_WIDTH;
    data->height = W_HEIGHT;
    data->image->img = mlx_new_image(data->mlx, data->width, data->height);
    data->image->addr = mlx_get_data_addr(data->image->img, &data->image->pixel_bits, &data->image->size_line, &data->image->endian);
    y =-1;
    while ( ++y < data->height)
    {
        x = -1;
        while (++x < data->width)
        {
            if (y < data->height / 2) 
                put_pixel_to_image(data, x, y, data->image->ceiling_color);
            else 
                put_pixel_to_image(data, x, y, data->image->floor_color);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}

int init_windows(t_game *game)
{
    
    game->mlx = mlx_init();
    if(!game->mlx)
        return (printf("Error\nmlx_init failed\n"), 0);
    if(!init_textures(game))
        return (printf("Error\nFalied to init textures\n"), 0);
    game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
    if (!game->win)
        return  (printf("Error\nFalied to creat windows\n"), 0);

    render(game);
    mlx_hook(game->win, 17, 0, ft_clean_game, game); 
    mlx_hook(game->win, 2, 1L, event_key, game);
    mlx_loop(game->mlx);  
    return (1);     
}
