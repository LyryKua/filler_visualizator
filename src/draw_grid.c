/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:48:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 19:48:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "visualizator.h"
#include "libft.h"

static void	horizontal(t_graphics *graphics, int x)
{
	int	i;
	int	j;
	int	finish;

	i = x;
	while (i < graphics->height_win)
	{
		finish = i + (int)rint(x * 0.1);
		while (i < finish)
		{
			j = 0;
			while (j < graphics->width_win)
			{
				graphics->put_pixel(graphics, i, j, 0x111111);
				j++;
			}
			i++;
		}
		i += x;
	}
}

static void	vertical(t_graphics *graphics, int x)
{
	int	i;
	int	j;
	int	finish;

	i = x;
	while (i < graphics->width_win)
	{
		finish = i + (int)rint(x * 0.1);
		while (i < finish)
		{
			j = 0;
			while (j < graphics->height_win)
			{
				graphics->put_pixel(graphics, j, i, 0x111111);
				j++;
			}
			i++;
		}
		i += x;
	}
}

void		draw_grid(t_graphics *graphics, int x)
{
	ft_bzero(graphics->addr,
						(size_t)graphics->width_win * graphics->height_win * 4);
	horizontal(graphics, x);
	vertical(graphics, x);
}
