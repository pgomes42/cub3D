/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:42 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 15:47:53 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_minimalist_map(t_map *map, int i)
{
    char    **tmp;
    int     height;
    
    height = 0;
    tmp = map->map;
    map->minimalist = (char **)malloc(sizeof(char *) * (map->height - 4));
    while (tmp && tmp[i] && ft_line_empty(tmp[i]))
        i++;
    while (tmp && tmp[i] && i < map->height)
    {
        if (!ft_line_empty(tmp[i]))
            tmp[i][ft_strlen(tmp[i]) - 1] = '\0';
        map->minimalist[height] = ft_strdup(tmp[i]);
        height++;
        i++;
    }
    map->minimalist[height] = NULL;
    ft_clean_matrix(tmp);
    map->height = height;
}

static int  add_line(t_map *gameMap, char *line)
{
    char    **tmp;
    int     i;
    
    i = 0;
    if (!line)
        return (0);
    tmp = (char **)malloc(sizeof(char *) * (gameMap->height + 2));
    if (!tmp)
        return (0);
    while (i < gameMap->height)
    {
        tmp[i] = gameMap->map[i];
        i++;
    }
    tmp[i] = line;
    tmp[i + 1] = NULL;
    if (gameMap->map)
        free(gameMap->map);
    gameMap->map = tmp;
    gameMap->height++;
    return (1);
}

static void init_obj_map(t_game *game, char **line, int *i)
{
    int   num_line;
    
    num_line = 0;
    line = game->map->map;
    while (line && line[++(*i)] && num_line <= 5)
    {
        if (ft_line_empty(line[*i]))
            continue ;
        else 
            line[*i][ft_strlen(line[*i]) - 1] = '\0';
        if (ft_isargs_valid(line[*i]))
            num_line++;
        if (ft_strncmp(line[*i], "NO", 2) == 0)
            game->map->no_texture = ft_strdup(&line[*i][3]);
        else if (ft_strncmp(line[*i], "SO", 2) == 0)
            game->map->so_texture = ft_strdup(&line[*i][3]);
        else if (ft_strncmp(line[*i], "WE", 2) == 0)
            game->map->we_texture = ft_strdup(&line[*i][3]);
        else if (ft_strncmp(line[*i], "EA", 2) == 0)
            game->map->ea_texture = ft_strdup(&line[*i][3]);
        else if (ft_strncmp(line[*i], "C", 1) == 0)
            game->map->ceiling_color = ft_strdup(&line[*i][2]);
        else if (ft_strncmp(line[*i], "F", 1) == 0)
            game->map->floor_color = ft_strdup(&line[*i][2]);
    }
}

static int    init_map(t_game *game, char *file)
{
    char    *line;
    int     fd;
    int     i;
    
    game->map->height = 0;
    if (ft_strncmp(&file[ft_strlen(file) - 4], ".cub", 4) != 0)
        return (perror("Error\nInvalid file extension\n"), 0);
    fd = open(file, O_RDONLY);
    if (fd < 0)
       return (perror("Error\nNo sush file or directory\n"), 0);
    while (1)
    {
        line = get_next_line(fd);
        if (!add_line(game->map, line))
            break ;
    }
    close (fd);
    if (!game->map->map)
			return (perror("ERROR\nMap empty!\n"), 0);
    i = -1;
    init_obj_map(game, game->map->map, &i);
    init_minimalist_map(game->map, i);
    return (1);
}

void    init_args(t_game *game, char *file)
{
    game->map = ft_calloc(1, sizeof(t_map));
    if (init_map(game, file))
        validate_map(game);
}