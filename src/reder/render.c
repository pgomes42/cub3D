/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:45 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/27 11:07:59 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void render_floor_ceiling(t_game *data)
{
    
    int x;
    int y;
     y =-1;
    while ( ++y < data->height)
    {
        x = -1;
        while (++x < data->width)
        {
            if (y < data->height / 2) 
                put_pixel_to_image(&data->image, x, y, data->ceiling_color);
            else 
                put_pixel_to_image(&data->image, x, y, data->floor_color);
        }
    }
   
          
}
int ft_draw(t_game *data) 
{
    render_floor_ceiling(data);
    raycasting(data);
    mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
    return (1);
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
    game->ray = (t_raycst *)malloc(sizeof(t_raycst)); 
      
    game->width = W_WIDTH;
    game->height = W_HEIGHT;
    game->image.img = mlx_new_image(game->mlx, game->width, game->height);
    game->image.addr =(char  *) mlx_get_data_addr(game->image.img, 
        &game->image.pixel_bits, &game->image.size_line, &game->image.endian);
 
    mlx_loop_hook(game->mlx, &ft_draw, game);
    mlx_hook(game->win, 17, 0, ft_clean_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game); 
    mlx_hook(game->win, KeyRelease, KeyReleaseMask, event_key, game);
	mlx_loop(game->mlx);  
    return (1);     
}
