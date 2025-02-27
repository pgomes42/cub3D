/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:55:50 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/27 12:09:44 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    ft_init_player_continue(t_player *player)
{
    player->dir_y = 0;
    player->dir_x = 0;
    player->plane_x = 0;
    player->plane_y = 0.66;
    player->move_speed = 0.05;
    player->rot_speed = 0.05;
}
void ft_init_player(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map->minimalist[++i])
    {
        j = -1;
        while (game->map->minimalist[i][++j])
        {
            if (ft_isplayer(game->map->minimalist[i][j]))
            {
                game->player->pos_x = j + 0.5;
                game->player->pos_y = i + 0.5;
                ft_init_player_continue(game->player);
                if (game->map->minimalist[i][j] == 'N')
                    game->player->dir_y = -1;
                else if (game->map->minimalist[i][j] == 'S')
                    game->player->dir_y = 1;
                else if (game->map->minimalist[i][j] == 'W')
                    game->player->dir_x = -1;
                else if (game->map->minimalist[i][j] == 'E')
                    game->player->dir_x = 1;
            }
        }
    }
}

int   ft_line_empty(char *line)
{
    int i;

    if(!line)
        return (0);
    i = 0;
    while (line && (line[i] == ' ' ||
    line[i] == '\t' || line[i] == '\n'))
    {
        i++;
        if (line[i] == '\0')
            return (1);
    }
    return (0);
}
int ft_isargs_valid(char *line)
{
   return (ft_strncmp(line, "NO", 2) == 0
        || ft_strncmp(line, "SO", 2) == 0
        ||ft_strncmp(line, "WE", 2) == 0
        || ft_strncmp(line, "EA", 2) == 0
        || ft_strncmp(line, "F", 1) == 0
        || ft_strncmp(line, "C", 1) == 0);
}

int    ft_get_color(char *color)
{
    int r;
    int g;
    int b;
    char **tmp_number;
    
    tmp_number = ft_split(color, ',');
    r = ft_atoi(tmp_number[0]);
    g = ft_atoi(tmp_number[1]);
    b = ft_atoi(tmp_number[2]);
    ft_clean_matrix(tmp_number);
    return (r << 16 | g << 8 | b);
}