/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:16:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/08 11:16:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "color.h"
# include "key_events.h"
# include "key_map.h"

typedef struct s_graphics	t_graphics;
typedef struct s_rect		t_rect;
typedef struct s_point		t_point;

struct	s_point
{
	int				x;
	int				y;
	unsigned int	color;
};

struct	s_rect
{
	int	x;
	int	y;
	int	w;
};

struct	s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		sl;
	int		e;
	int		width_win;
	int		height_win;
	void	(*put_pixel)(t_graphics *, int, int, unsigned int);
	void	(*destructor)(t_graphics **);
};

t_graphics	*init_graphics(int width, int height, char *title);

#endif