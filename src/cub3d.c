/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:56:51 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/11 12:13:16 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_game  game;
    
    if (argc != 2)
    {
        printf("Error\nInvalid number of arguments\n");
        return (0);
    }
    init_args(&game, argv[1]);
    init_windows(&game);
    ft_clean_map(game.map);
    return (0);
}
