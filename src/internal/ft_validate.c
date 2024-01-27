/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/27 20:26:34 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_validate.h"

static int32_t	ft_check_map_proportion(char *column, t_canvas *data);
static void		ft_check_elements(char *column, char **message, t_canvas *data);

void	ft_is_map_valid(char *column, char **message, t_canvas *data, \
			int32_t last_line)
{
	if (!ft_check_map_proportion(column, data))
		*message = ft_strdup("Invalid map - Map doesn't have proportion.");
	else if (!ft_check_wall(column, data, last_line))
		*message = ft_strdup("Invalid map - Map is not surrounded by walls.");
	if (data->line && !last_line)
		ft_check_elements(column, message, data);
	else if (last_line && data->player == 0)
		*message = ft_strdup("Invalid map - Map need at least a player.");
	else if (last_line && data->exit == 0)
		*message = ft_strdup("Invalid map - Map need at least an exit.");
	else if (last_line && data->collectable == 0)
		*message = ft_strdup("Invalid map - Map need at least a collectable.");
}

int32_t	ft_check_wall(char *column, t_canvas *data, int32_t last_line)
{
	int32_t	i;

	i = -1;
	if (data->line == 0 || last_line == TRUE)
	{
		while (column[++i])
		{
			if (column[i] == '\n')
				return (TRUE);
			if (column[i] != WALL)
				return (FALSE);
		}
	}
	else if (column[0] != WALL || column[data->column - 2] != WALL)
		return (FALSE);
	return (TRUE);
}

static int32_t	ft_check_map_proportion(char *column, t_canvas *data)
{
	if (data->column < COLUMN_MINIMUM)
		return (FALSE);
	else if ((size_t)data->column != ft_strlen(column))
		return (FALSE);
	return (TRUE);
}

static void	ft_check_elements(char *column, char **message, t_canvas *data)
{
	int32_t	i;

	i = -1;
	while (column[++i])
	{
		if (column[i] == 'P')
			data->player++;
		else if (column[i] == 'C')
			data->collectable++;
		else if (column[i] == 'E')
			data->exit++;
		if (data->player > ELEMENT_MINIMUM)
		{
			*message = ft_strdup("Invalid map - Too many players.");
			break ;
		}
		if (data->exit > ELEMENT_MINIMUM)
		{
			*message = ft_strdup("Invalid map - Too many exits.");
			break ;
		}
	}
}
