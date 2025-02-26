/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:48:25 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/25 10:59:15 by pgomes           ###   ########.fr       */
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
    
    map->width = bigger_size_line(map); 
    map->aux_map = (char **)malloc(sizeof(char *) * (map->width + 1));
    map->aux_map[map->width] = NULL;
    i = -1;
    while(++i < map->width)
    {
        map->aux_map[i] = (char *)malloc(sizeof(char) * (map->height + 1));
        map->aux_map[i][map->height] = '\0';
    }
       i = -1;  
   while( ++i < map->height)
    {
        j = -1;
        while(++j < map->width)
        {
            if(j < (int)ft_strlen(map->minimalist[i]))
                map->aux_map[j][i] = map->minimalist[i][j];
            else
                map->aux_map[j][i] = ' ';
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
