/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:48 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 16:31:49 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	ft_go_up(t_game *mlx)
{
	mlx->player->pos_x += mlx->player->player_delta_x;
	mlx->player->pos_y += mlx->player->player_delta_y;
}

static void	ft_go_down(t_game *mlx)
{
	mlx->player->pos_x -= mlx->player->player_delta_x;
	mlx->player->pos_y -= mlx->player->player_delta_y;
}

static void	ft_go_left(t_game *mlx)
{
	mlx->player->pos_x += mlx->player->player_delta_y * 0.63;
	mlx->player->pos_y -= mlx->player->player_delta_x * 0.63;
}

static void	ft_go_right(t_game *mlx)
{
	mlx->player->pos_x -= mlx->player->player_delta_y * 0.63;
	mlx->player->pos_y += mlx->player->player_delta_x * 0.63;
}

int	arrow_keys(int Key, t_game *mlx)
{
		if (Key == XK_Left)
		ft_rotate_left(mlx);
	if (Key == XK_Right)
		ft_rotate_right(mlx);
	if (Key == XK_Up || Key == XK_w)
		ft_go_up(mlx);
	if (Key == XK_Down || Key == XK_s)
		ft_go_down(mlx);
	if (Key == XK_a)
		ft_go_left(mlx);
	if (Key == XK_d)
		ft_go_right(mlx);
	return (0);
}