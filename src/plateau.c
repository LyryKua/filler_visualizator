/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:48:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 19:48:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <zconf.h>
#include "libft.h"
#include "visualizator.h"

static t_sqr	*read_plateau(t_all *all, char *str)
{
	t_sqr	*plateau;
	char	*line;
	int		i;

	plateau = (t_sqr *)malloc(sizeof(t_sqr));
	plateau->rows = ft_atoi(ft_strchr(str, ' '));
	plateau->columns = ft_atoi(ft_strrchr(str, ' '));
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	plateau->sqr = (char **)malloc(plateau->rows * sizeof(char *));
	i = 0;
	while (i < plateau->rows)
	{
		get_next_line(STDIN_FILENO, &line);
		if (ft_isdigit(line[0]) && ft_isdigit(line[1])
									&& ft_isdigit(line[2]) && line[3] == ' ')
		{
			plateau->sqr[i++] = ft_strdup(ft_strchr(line, ' ') + 1);
			ft_strdel(&line);
		}
		else
			close_window(all,
				"The number of rows doesn't correspond to the input values");
	}
	return (plateau);
}

static void		destruct_stuff(t_sqr **sqr)
{
	int	i;

	if (*sqr)
	{
		i = 0;
		if ((*sqr)->sqr)
		{
			while (i < (*sqr)->rows)
				ft_strdel(&(*sqr)->sqr[i++]);
			free((*sqr)->sqr);
			(*sqr)->sqr = NULL;
		}
		free(*sqr);
		*sqr = NULL;
	}
}

t_stuff			*init_stuff(void)
{
	t_stuff	*stuff;

	stuff = (t_stuff *)malloc(sizeof(t_stuff));
	stuff->plateau = NULL;
	stuff->read = read_plateau;
	stuff->destructor = destruct_stuff;
	return (stuff);
}
