/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:58:59 by pgomes            #+#    #+#             */
/*   Updated: 2025/03/03 11:15:24 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel_to_image(t_img *img, int x, int y, int color)
{     
    char	*pixel;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

int get_texture_pixel(t_texture *tex, int x, int y)
{
    char	*pixel;

	if (x < 0 || x >= W_HEIGHT ||
         y < 0 || y >= W_HEIGHT)
		return (-1);
	pixel = tex->addr + (y * tex->size_line + x * (tex->pixel_bits / 8));
	return (*(int *)pixel);
}