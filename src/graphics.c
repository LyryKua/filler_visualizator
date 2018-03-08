/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:47:24 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:28 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "graphics.h"
#include "libft.h"

static void		put_pixel_to_img(t_graphics *graphics, int y, int x,
															unsigned int color)
{
	if (x >= graphics->width_win || x < 0 || y >= graphics->height_win || y < 0)
		return ;
	ft_memcpy(graphics->addr + (x * 4 + y * graphics->sl), &color, 4);
}

static void		destruct_graphics(t_graphics **graphics)
{
	if (*graphics)
	{
		mlx_destroy_image((*graphics)->mlx, (*graphics)->img);
		mlx_destroy_window((*graphics)->mlx, (*graphics)->win);
		free(*graphics);
		*graphics = NULL;
	}
}

t_graphics		*init_graphics(int width, int height, char *title)
{
	t_graphics	*graphics;

	graphics = (t_graphics *)malloc(sizeof(t_graphics));
	graphics->mlx = mlx_init();
	graphics->win = mlx_new_window(graphics->mlx, width, height, title);
	graphics->img = mlx_new_image(graphics->mlx, width, height);
	graphics->addr = mlx_get_data_addr(graphics->img, &graphics->bpp,
												&graphics->sl, &graphics->e);
	graphics->width_win = width;
	graphics->height_win = height;
	graphics->put_pixel = put_pixel_to_img;
	graphics->destructor = destruct_graphics;
	return (graphics);
}
