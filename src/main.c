/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:38:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/10/16 16:38:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include <zconf.h>
#include <stdbool.h>
#include <math.h>
#include "graphics.h"
#include "visualizator.h"
#include "libft.h"

static int		esc_exit(int keycode, t_all *all)
{
	if (keycode == ESC)
		close_window(all, NULL);
	return (0);
}

static void		finish_read(char *line)
{
	char	*str;

	if (ft_strstr(line, "=="))
	{
		ft_putendl(line);
		if (get_next_line(STDIN_FILENO, &str) == 1)
		{
			ft_putendl(str);
			ft_strdel(&str);
		}
	}
}

static int		visualization(t_all *all)
{
	char	*line;
	char	*tmp;

	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		tmp = line;
		if (ft_strstr(line, "Plateau") && (tmp = ft_strchr(line, ' ')))
		{
			all->instance->plateau = all->instance->read(all, line);
			draw_grid(all->graphics, all->x);
			draw(all->graphics, all->instance, all->x);
			mlx_put_image_to_window(all->graphics->mlx, all->graphics->win,
													all->graphics->img, 0, 0);
			all->instance->destructor(&all->instance->plateau);
			ft_strdel(&line);
			break ;
		}
		if (!tmp)
			error_exit("Plateau XX XX");
		finish_read(line);
		ft_strdel(&line);
	}
	return (0);
}

static t_sqr	*get_height_width()
{
	char	*line;
	t_sqr	*sqr;
	char	*tmp;

	sqr = (t_sqr *)malloc(sizeof(t_sqr));
	sqr->sqr = NULL;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		tmp = line;
		if (ft_strstr(line, "Plateau") && (tmp = ft_strchr(line, ' ')))
		{
			sqr->rows = ft_atoi(ft_strchr(line, ' '));
			sqr->columns = ft_atoi(ft_strrchr(line, ' '));
			if (!sqr->rows || !sqr->columns)
				error_exit("Rows and columns should be greater than 0");
			ft_strdel(&line);
			break ;
		}
		if (!tmp)
			error_exit("Plateau XX XX");
		ft_strdel(&line);
	}
	return (sqr);
}

int				main(int argc, char *argv[])
{
	t_all		all;
	t_graphics	*graphics;
	t_sqr		*sqr;

	all.instance = init_stuff();
	all.x = 30;
	sqr = get_height_width();
	if (sqr->rows > 63)
		all.x = 10;
	else if (sqr->rows > 42)
		all.x = 20;
	graphics = init_graphics(
			(int)rint(sqr->columns * all.x * 1.1 - all.x * 0.1),
			(int)rint(sqr->rows * all.x * 1.1 - all.x * 0.1),
			"Visualisator");
	all.instance->destructor(&sqr);
	all.graphics = graphics;
	mlx_key_hook(graphics->win, esc_exit, &all);
	mlx_hook(graphics->win, DESTROY_NOTIFY, (1L << 17), close_window, &all);
	mlx_loop_hook(graphics->mlx, visualization, &all);
	mlx_loop(graphics->mlx);
	return (0);
}
