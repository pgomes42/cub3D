/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:48 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 11:15:00 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	key_press_handler(int key, t_game *game)
{
	if (key == XK_Escape)
        ft_clean_game(game);
	if (key == XK_Left)
		game->player->rotate -= 1;
	if (key == XK_Right)
		game->player->rotate += 1;
	if (key == XK_w)
		game->player->move_y = 1;
	if (key == XK_a)
		game->player->move_x = -1;
	if (key == XK_s)
		game->player->move_y = -1;
	if (key == XK_d)
		game->player->move_x = 1;
	return (0);
}

int event_key(int key, t_game *game)
{
    if (key == XK_Escape)
        ft_clean_game(game);
    if (key == XK_w && game->player->move_y == 1)
		game->player->move_y = 0;
	if (key == XK_s && game->player->move_y == -1)
		game->player->move_y = 0;
	if (key == XK_a && game->player->move_x == -1)
		game->player->move_x += 1;
	if (key == XK_d && game->player->move_x == 1)
		game->player->move_x -= 1;
	if (key == XK_Left && game->player->rotate <= 1)
		game->player->rotate = 0;
	if (key == XK_Right && game->player->rotate >= -1)
		game->player->rotate = 0;
	return (0);
}