/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:47:24 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:28 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H

# include "graphics.h"

# define WIDTH	1440
# define HEIGHT	900
# define X	20



/* ************************************************************************** */


typedef struct s_sqr	t_sqr;
typedef struct s_stuff	t_stuff;
typedef struct s_all	t_all;

struct	s_all
{
	t_stuff		*instance;
	t_graphics	*graphics;
	int			x;
};

struct	s_sqr
{
	int		rows;
	int		columns;
	char	**sqr;
};

struct	s_stuff
{
	t_sqr	*plateau;
	t_sqr	*(*read)(t_all *, char *);
	void	(*destructor)(t_sqr **);
};

t_stuff	*init_stuff();

void	draw(t_graphics *graphics, t_stuff *instance, int x);
void	fill_rectangle(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_old_x(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_new_x(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_old_o(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_new_o(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_grid(t_graphics *graphics, int x);

int		close_window(t_all *all, char *msg);
void	error_exit(char *msg);

#endif
