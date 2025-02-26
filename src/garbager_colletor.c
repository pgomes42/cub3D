/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbager_colletor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:30:09 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 11:42:04 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_clean_matrix(char **matrix)
{
    int i;

    i = -1;
    while (matrix  && matrix[++i])
        free(matrix[i]);
    free(matrix);
}
void    ft_clean_map(t_map *map)
{
    ft_clean_matrix(map->aux_map);
    ft_clean_matrix(map->minimalist);
    if (map->no_texture)
        free(map->no_texture);
    if (map->so_texture)
        free(map->so_texture);
    if (map->we_texture)
        free(map->we_texture);
    if (map->ea_texture)    
        free(map->ea_texture);
    if (map->floor_color)
        free(map->floor_color);
    if (map->ceiling_color)
        free(map->ceiling_color);
    free(map);
}

void ft_clean_texture(t_game *game)
{
    if (game->s_wall.img)
        mlx_destroy_image(game->mlx, game->s_wall.img);
    if (game->n_wall.img)
        mlx_destroy_image(game->mlx, game->n_wall.img);
    if (game->e_wall.img)
        mlx_destroy_image(game->mlx, game->e_wall.img);
    if (game->w_wall.img)
        mlx_destroy_image(game->mlx, game->w_wall.img);
    //if(game->texture)
      //  free(game->texture);
}

int    ft_clean_game(t_game *game)
{
   
    if (game->mlx)
        mlx_destroy_window(game->mlx, game->win);
    //mlx_destroy_image(game->mlx, game->img);
    ft_clean_texture(game);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free(game->player);
    if (game->map)
        ft_clean_map(game->map);
    exit(0);
    return (0);
}
