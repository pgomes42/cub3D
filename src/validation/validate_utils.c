/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:48:25 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/11 14:19:52 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_map(t_map *map, char **min)
{
    int i;
     i = -1;
   
    printf("%s", map->no_texture);
    printf("%s",map->so_texture);
    printf("%s", map->we_texture);
    printf("%s", map->ea_texture);
    printf("%s", map->floor_color);
    printf("%s",map->ceiling_color);
    while (min[++i])
    {
        
        printf("%s\n",min[i]);
        
    }
}

static int bigger_size_line(t_map *map)
{
    int i;
    int bigger;
    int bigger_line;
   
    bigger_line = 0;
    i = 0;
    while(map->minimalist[i])
    {
        bigger = ft_strlen(map->minimalist[i]);
        if(bigger > bigger_line)
            bigger_line = bigger;
        i++;
    }
    return (bigger_line);
}
int     ft_isplayer(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int    traspost_matriz(t_map *map)
{
    int i;
    int j;
    
    map->map_rev_height = bigger_size_line(map); 
    map->reverter_map = (char **)malloc(sizeof(char *) * (map->map_rev_height + 1));
    map->reverter_map[map->map_rev_height] = NULL;
    i = -1;
    while(++i < map->map_rev_height)
    {
        map->reverter_map[i] = (char *)malloc(sizeof(char) * (map->map_height + 1));
        map->reverter_map[i][map->map_height] = '\0';
    }
       i = -1;  
   while( ++i < map->map_height)
    {
        j = -1;
        while(++j < map->map_rev_height)
        {
            if(j < (int)ft_strlen(map->minimalist[i]))
                map->reverter_map[j][i] = map->minimalist[i][j];
            else
                map->reverter_map[j][i] = ' ';
        }       
    }
    return (1);    
}

int ft_iscolor_valid(char *color)
{
    int i;
    int numbers;
    char **split;
    
    split = ft_split(color, ',');
    i = 0;
    while (split && split[i])
    {
        numbers = ft_atoi(split[i]);
        if (numbers < 0 || numbers > 255)
            return (ft_clean_matrix(split), 0);
        i++;
    }
    ft_clean_matrix(split);
    return (1);   
}
