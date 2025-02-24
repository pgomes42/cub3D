/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:58:59 by pgomes            #+#    #+#             */
/*   Updated: 2025/02/12 10:11:37 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel_to_image(t_image *image, int x, int y, int color)
{     
    int pixel;
    pixel = (y * image->size_line + x * (image->pixel_bits / 8));
    *(unsigned int *)dst = color;
}