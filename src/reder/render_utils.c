/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:58:59 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/26 11:23:28 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel_to_image(t_texture *image, int x, int y, int color)
{     
    int *dst;
    /*
    dst =(int *)(y * image->size_line + x * (image->pixel_bits / 8));
    *(unsigned int *)dst = color;
    char *dst;*/

    dst = image->addr + (y * image->size_line + x * (image->pixel_bits / 8));
    *(unsigned int *)dst = color;
}

int get_texture_pixel(t_texture *tex, int x, int y)
{
    if(x < 0 || x >= TILE_SIZE || y < 0 || y >= TILE_SIZE)
        return (0x00000000);
    return (tex->addr[y * tex->size_line + x]);
}