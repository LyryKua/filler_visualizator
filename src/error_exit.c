/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:06:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/08 13:06:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include <stdlib.h>
#include "libft.h"
#include "visualizator.h"

int		close_window(t_all *all, char *msg)
{
	all->graphics->destructor(&all->graphics);
//	close(all->fd);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(0);
}

void	error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(42);
}
