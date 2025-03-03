/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:57:46 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 11:33:37 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "cub3d.h"


 static int verif_wall(char **map, int map_height)
{
    int i;
    int j;
    int lenght;
    char    **lines;

    i = 0;
    while (i < map_height)
    {
        lines = ft_split(map[i], ' ');
      j = 0;
      while (lines[j])
      {
        lenght = ft_strlen(lines[j]);
        if (lines[j][0] != '1' || lines[j][lenght - 1] != '1')
        {
            ft_clean_matrix(lines);
            return (printf("Error\nInvalid map\n"), 0);
        }
        j++;
    }
        ft_clean_matrix(lines);
        i++;
    }
    return (1);        
}

static int validate_texture(t_map *map)
{
    if (!map->no_texture
        || (ft_strncmp(&map->no_texture[ft_strlen(map->no_texture) - 4], ".xpm", 4)) != 0)
       return(perror("Error\nMissing NO information in map file\n"), 0);
    else if (!map->so_texture
        || (ft_strncmp(&map->so_texture[ft_strlen(map->so_texture) - 4], ".xpm", 4)) != 0)
         return(perror("Error\nMissing SO information in map file\n"), 0);
    else if (!map->we_texture
        || (ft_strncmp(&map->we_texture[ft_strlen(map->we_texture) - 4], ".xpm", 4)) != 0)
         return(perror("Error\nMissing WE information in map file\n"), 0);
    else if (!map->ea_texture
        || (ft_strncmp(&map->ea_texture[ft_strlen(map->ea_texture) - 4], ".xpm", 4)) != 0)
         return(perror("Error\nMissing EA information in map file\n"), 0);
    else if (!map->floor_color || !ft_iscolor_valid(map->floor_color))
         return(perror("Error\nInformation of floor color is invalid\n"), 0);
    else if (!map->ceiling_color || !ft_iscolor_valid(map->ceiling_color))
         return(perror("Error\nInformation of ceiling color is invalid\n"), 0);
    return (1); 
}

static int count_player(t_map *map)
{
    int i;
    int j;
    int is_player;
    
    i = 0;
    is_player = 0;
    while (map->minimalist[i])
    {
        j = 0;
        while (map->minimalist[i][j])
        {
            if (ft_isplayer(map->minimalist[i][j]))
                is_player++;
            j++;
        }
        i++;
    }
    if (is_player != 1)
        return (printf("Error\nInvalid number of players\n"), 0);
    return (1);  
}

static int validate_elements(t_map *map)
{
    int i;
    int j;
   
    i = 0;
    while (map->minimalist[i])
    {
        j = 0;
        while (map->minimalist[i][j])
        {
            if (map->minimalist[i][j] != '1' && map->minimalist[i][j] != '0'
            && !ft_isplayer(map->minimalist[i][j])
            && map->minimalist[i][j] != ' ')
                return (printf("Error\n Invalid arguments of the map\n"), 0);
            j++;
       }
        i++;
    }
    return (1);
}

int     validate_map(t_game *game)
{
    if (validate_texture(game->map)
    && verif_wall(game->map->minimalist, game->map->height)
    && traspost_matriz(game->map)
    && verif_wall(game->map->aux_map, game->map->width)
    && validate_elements(game->map) && count_player(game->map))
    {
        if (game->map->minimalist[0])
            printf("Valid map\n");
        game->player = (t_player *)malloc(sizeof(t_player));
        game->player->player_angle = ft_init_player(game);
	    game->player->player_delta_x = cos(game->player->player_angle) * 7;
	    game->player->player_delta_y = sin(game->player->player_angle) * 7;
        game->floor_color = ft_get_color(game->map->floor_color);
        game->ceiling_color = ft_get_color(game->map->ceiling_color);
        return  (1);
    }  
    return (0);   
}
