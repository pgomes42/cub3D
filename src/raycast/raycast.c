/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:33:44 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 16:32:14 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_pos_in_map(t_game *data, int x, int y)
{
   // printf("x: %d, y: %d\n", x, y);
   // printf("2 x: %d, y: %d\n", data->map->height, data->map->width);
	return  ((x < 0 || x >= (int)ft_strlen(data->map->minimalist[y]))
		|| (y < 0 || y >= (int)ft_strlen(data->map->aux_map[x])));
		
}
static void	ft_horizontal_init(t_game *win, t_intersection *vars, float ra)
{
	vars->tan = -1 / tan(ra);
	vars->dof = 0;
	if (ra > PI)
	{
		vars->ry = (((int)win->player->pos_y / SQUARE) * SQUARE) - 0.0001;
		vars->rx = (win->player->pos_y - vars->ry) * vars->tan + win->player->pos_x;
		vars->yo = -SQUARE;
		vars->xo = -vars->yo * vars->tan;
	}
	else if (ra < PI)
	{
		vars->ry = (((int)win->player->pos_y / SQUARE) * SQUARE) + SQUARE;
		vars->rx = (win->player->pos_x - vars->ry) * vars->tan + win->player->pos_x;
		vars->yo = SQUARE;
		vars->xo = -vars->yo * vars->tan;
	}
	else if (ra == 0 || ra == PI)
	{
		vars->rx = win->player->pos_x;
		vars->ry = win->player->plane_y;
		vars->dof = 64;
	}
}

static void	hor_inse(t_game *win, float ra, float *hx, float *hy)
{
	t_intersection	vars;

	ft_horizontal_init(win, &vars, ra);
	while (vars.dof < 64)
	{
		vars.mx = (int)(vars.rx / SQUARE);
		vars.my = (int)(vars.ry / SQUARE);
        
		if ((vars.my >= win->map->height
            || vars.mx >= win->map->width) || is_valid_pos_in_map(win, vars.mx, vars.my))
			break ;
		if (win->map->minimalist[vars.my][vars.mx] == '1')
			break ;
		else
		{
			vars.rx += vars.xo;
			vars.ry += vars.yo;
			vars.dof++;
		}
	}
	*hx = vars.rx;
	*hy = vars.ry;
}

static void	ft_vertical_init(t_game *win, t_intersection *vars, float ra)
{
	vars->tan = -tan(ra);
	vars->dof = 0;
	if (ra > P2 && ra < P3)
	{
		vars->rx = (((int)win->player->pos_x / SQUARE) * SQUARE) - 0.001;
		vars->ry = (win->player->pos_x - vars->rx) * vars->tan + win->player->pos_y;
		vars->xo = -SQUARE;
		vars->yo = -vars->xo * vars->tan;
	}
	else if (ra < P2 || ra > P3)
	{
		vars->rx = (((int)win->player->pos_x / SQUARE) * SQUARE) + SQUARE;
		vars->ry = (win->player->pos_x - vars->rx) * vars->tan + win->player->pos_y;
		vars->xo = SQUARE;
		vars->yo = -vars->xo * vars->tan;
	}
	else if (ra == 0 || ra == PI)
	{
		vars->rx = win->player->pos_x;
		vars->ry = win->player->pos_y;
		vars->dof = 64;
	}
}

static void	ver_inse(t_game *win, float ra, float *vx, float *vy)
{
	t_intersection	vars;

	ft_vertical_init(win, &vars, ra);
	while (vars.dof < 64)
	{
		vars.mx = (int)(vars.rx / SQUARE);
		vars.my = (int)(vars.ry / SQUARE);
		if ((vars.mx >= win->map->width
            || vars.my >= win->map->height) ||is_valid_pos_in_map(win, vars.mx, vars.my))
			break ;
        if (win->map->minimalist[vars.my][vars.mx] == '1')
			break ;
		else
		{
			vars.rx += vars.xo;
			vars.ry += vars.yo;
			vars.dof++;
		}
	}
	*vx = vars.rx;
	*vy = vars.ry;
}

void	raycaster(t_game *win)
{
	t_raycst	vars;

	ft_init_vars(&vars, win);
	while (++vars.r < W_WIDTH && ft_circle_normalizer(&vars.ra) == 1)
	{
		hor_inse(win, vars.ra, &vars.hx, &vars.hy);
		ver_inse(win, vars.ra, &vars.vx, &vars.vy);
		vars.ray_h = line_length(win->player->pos_x, win->player->pos_y,
				vars.hx, vars.hy);
		vars.ray_v = line_length(win->player->pos_y, win->player->pos_y,
				vars.vx, vars.vy);
		if (vars.ray_h < vars.ray_v)
		{
			ft_set_tex(win, vars.hy, 'h');
			ft_value_setter(&vars.wall_x, &vars.hx, &vars.line, &vars.ray_h);
		}
		else
		{
			ft_set_tex(win, vars.vx, 'v');
			ft_value_setter(&vars.wall_x, &vars.vy, &vars.line, &vars.ray_v);
		}
		vars.line = vars.line * cos(win->player->player_angle - vars.ra);
		draw_3d_walls(win, vars.line, vars.r, vars.wall_x);
		vars.ra += DR;
	}
}