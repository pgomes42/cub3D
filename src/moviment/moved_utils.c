/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moved_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:24:14 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/27 10:40:01 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	is_valid_pos_in_map(t_game *data, double x, double y)
{
	return  (!(x < 0.25 || x >= ft_strlen(data->map->minimalist[(int)y]) - 1.25)
		|| !(y < 0.25 || y >= ft_strlen(data->map->aux_map[(int)x]) - 0.25));
		
}

static int	is_valid_pos(t_game *data, double x, double y)
{
	return ((is_valid_pos_in_map(data, x, y))
    || (data->map->aux_map[(int)y][(int)x] == '0'));
}

int	validate_move(t_game *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player->pos_y))
	{
		data->player->pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player->pos_x, new_y))
	{
		data->player->pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

void	ft_update_player(int px, int py, t_texture *img)
{
	float	y;
	float	x;
	int		size;

	
	size = PLAYER_SIZE;
	y = 0;
	while (y < size && y + py < HEIGHT)
	{
		x = 0;
		while (x < size && x + px < WIDTH)
		{
			if (x > 0 && y > 0)
				my_pixel_put(img, x + px - PLAYER_SIZE / 2,
					y + py - PLAYER_SIZE / 2, 0x0000F0);
			x++;
		}
		y++;
	}
}
