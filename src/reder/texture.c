/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:27 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/11 12:55:32 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int init_textures(t_game *game)
{
    int whidth;
    int height;
    printf("no_texture:%s", game->map->so_texture);
    game->s_wall = mlx_xpm_file_to_image(game->mlx, game->map->so_texture, &whidth, &height);
    if (!game->s_wall)
        return (printf("Error\nFalied to creat south wall\n"), 0);
    game->n_wall = mlx_xpm_file_to_image(game->mlx, game->map->no_texture, &whidth, &height);
    if (!game->n_wall)
        return (printf("Error\nFalied to creat north wall\n"), 0);
    game->e_wall = mlx_xpm_file_to_image(game->mlx, game->map->ea_texture, &whidth, &height);
    if (!game->e_wall)
        return (printf("Error\nFalied to creat east wall\n"), 0);
    game->w_wall = mlx_xpm_file_to_image(game->mlx, game->map->we_texture, &whidth, &height);
    if (!game->w_wall)
        return (printf("Error\nFalied to creat west wall\n"), 0);
    return (1);
}