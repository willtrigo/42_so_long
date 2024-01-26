/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/26 01:46:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_validate.h"

static int32_t	ft_check_map_proportion(char *column, t_canvas *data);

void	ft_is_map_valid(char *column, char **message, t_canvas *data, \
			int32_t last_line)
{
	if (!ft_check_map_proportion(column, data))
		*message = ft_strdup("Invalid map - Map doesn't have proportion.");
	else if (!ft_check_wall(column, data, last_line))
		*message = ft_strdup("Invalid map - Map is not surrounded by walls.");
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
