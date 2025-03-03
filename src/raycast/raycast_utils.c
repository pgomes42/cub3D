/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:40:40 by alexa             #+#    #+#             */
/*   Updated: 2025/03/03 10:29:46 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_tex(t_game *win, float ray_point, char c)
{
	if (c == 'h')
	{
		if (ray_point > win->player->pos_y)
			win->texture_nbr = 'N';
		else
			win->texture_nbr = 'S';
	}
	else
	{
		if (ray_point > win->player->pos_x)
			win->texture_nbr = 'W';
		else
			win->texture_nbr = 'E';
	}
}

void	ft_value_setter(float *val1, float *set1, float *val2, float *set2)
{
	*val1 = *set1;
	*val2 = *set2;
}
void	ft_init_vars(t_raycst	*vars, t_game *win)
{
	vars->r = -1;
	vars->ra = win->player->player_angle - (FOV / 2);
}
int	ft_circle_normalizer(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
	return (1);
}
float	line_length(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}