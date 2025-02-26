/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:13:43 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 11:03:44 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:31:24 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/10 12:34:32 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rotate_left_right(t_player *player, double rotspeed)
{
	double		tmp_x;

	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotspeed) - player->dir_y * sin(rotspeed);
	player->dir_y = tmp_x * sin(rotspeed) + player->dir_y * cos(rotspeed);
	tmp_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotspeed) - player->plane_y * sin(rotspeed);
	player->plane_y = tmp_x * sin(rotspeed) + player->plane_y * cos(rotspeed);
	return (1);
}

static int	rotate_player(t_game *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data->player, rotspeed);
	return (moved);
}

int	move_player(t_game *data)
{
	int	moved;
	t_player	*player;

	player = data->player;
	moved = 0;
	if (player->move_y == 1)
		moved += validate_move(data, player->pos_x + player->dir_x * MOVESPEED,
		player->pos_y + player->dir_y * MOVESPEED);
	if (player->move_y == -1)
		moved += validate_move(data, player->pos_x - player->dir_x * MOVESPEED,
		player->pos_y - player->dir_y * MOVESPEED);	
	if (player->move_x == -1)
		moved += validate_move(data, player->pos_x + player->dir_y * MOVESPEED,
		player->pos_x + player->dir_y * MOVESPEED);
	if (player->move_x == 1)
		moved += validate_move(data,  player->pos_x - player->dir_y * MOVESPEED,
		player->pos_y + player->dir_x * MOVESPEED);
	if (data->player->rotate != 0)
	{
		
	}
		moved += rotate_player(data, data->player->rotate);
	return (moved);
}
