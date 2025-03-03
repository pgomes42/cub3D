/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:45 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 11:44:30 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void render_floor_ceiling(t_game *data)
{
    
    int x;
    int y;
     y =-1;
    while ( ++y < W_HEIGHT)
    {
        x = -1;
        while (++x < W_WIDTH)
        {
            if (y < W_HEIGHT / 2) 
                put_pixel_to_image(&data->img, x, y, data->ceiling_color);
            else 
                put_pixel_to_image(&data->img, x, y, data->floor_color);
        }
    }
   
          
}
int ft_draw(t_game *data) 
{
    render_floor_ceiling(data);
    raycaster(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
    return (1);
}

int	ft_event_checker(int Key, t_game *mlx)
{
	if (Key == XK_Escape)
    ft_clean_game(mlx);
	return (0);
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
    game->img.mlx_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
    
    mlx_loop_hook(game->mlx, &ft_draw, game);
    mlx_key_hook(game->win, &arrow_keys, game);
    mlx_hook(game->win, 17, 0, ft_clean_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, ft_event_checker, game); 
    mlx_loop(game->mlx);  
    return (1);     
}
