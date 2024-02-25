/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/21 11:24:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_validate_bonus.h"

static int8_t	ft_check_map_proportion(char *column, t_canvas *data);
static void		ft_check_elements(char *column, char **message, \
	t_canvas *data, int32_t i);

void	ft_is_map_valid(char *column, char **message, t_canvas *data, \
	int8_t last_line)
{
	if (!ft_check_map_proportion(column, data))
		*message = ft_strdup("Invalid map - Map doesn't have proportion.");
	else if (!ft_check_wall(column, data, last_line))
		*message = ft_strdup("Invalid map - Map is not surrounded by walls.");
	if (data->val_data.line && !last_line)
		ft_check_elements(column, message, data, -1);
	else if (last_line && data->val_data.player == 0)
		*message = ft_strdup("Invalid map - Map need at least a player.");
	else if (last_line && data->val_data.exit == 0)
		*message = ft_strdup("Invalid map - Map need at least an exit.");
	else if (last_line && data->val_data.coll == 0)
		*message = ft_strdup("Invalid map - Map need at least a collectable.");
}

int8_t	ft_check_wall(char *column, t_canvas *data, int8_t last_line)
{
	int32_t	i;

	i = -1;
	if (data->val_data.line == 0 || last_line == TRUE)
	{
		while (column[++i])
		{
			if (column[i] == '\n')
				return (TRUE);
			if (column[i] != WALL)
				return (FALSE);
		}
	}
	else if (column[0] != WALL || column[data->val_data.column - 2] != WALL)
		return (FALSE);
	return (TRUE);
}

void	ft_validate_tile_size(t_canvas *data, char *buf)
{
	const int32_t	column = (WIDTH - TILE_SIZE_MAX) / data->val_data.column;
	const int32_t	line = (HEIGHT - TILE_SIZE_MAX) / data->val_data.line;

	if (column >= line && column > TILE_SIZE_MAX)
		data->val_data.tile_size = TILE_SIZE_MAX;
	else if (column >= line && (column <= TILE_SIZE_MAX \
		&& column >= TILE_SIZE_MIN))
		data->val_data.tile_size = line;
	else if (column < line && line > TILE_SIZE_MAX)
		data->val_data.tile_size = TILE_SIZE_MAX;
	else if (column < line && (line <= TILE_SIZE_MAX && line >= TILE_SIZE_MIN))
		data->val_data.tile_size = column;
	if ((column < TILE_SIZE_MIN) || (line < TILE_SIZE_MIN))
	{
		free(buf);
		ft_output_error("Invalid so long - Map file is too long.");
	}
	data->val_data.offset_x = (WIDTH - data->val_data.tile_size \
		* data->val_data.column) / 2;
	data->val_data.offset_y = (HEIGHT - data->val_data.tile_size \
		* data->val_data.line) / 2;
}

static int8_t	ft_check_map_proportion(char *column, t_canvas *data)
{
	if (data->val_data.column < COLUMN_MINIMUM)
		return (FALSE);
	else if ((size_t)data->val_data.column != ft_strlen(column))
		return (FALSE);
	return (TRUE);
}

static void	ft_check_elements(char *column, char **message, t_canvas *data, \
	int32_t i)
{
	while (column[++i])
	{
		if (column[i] == PLAYER)
			data->val_data.player++;
		else if (column[i] == COLL)
			data->val_data.coll++;
		else if (column[i] == EXIT_DOOR)
			data->val_data.exit++;
		else if ((column[i] != WALL) && (column[i] != FLOOR) \
			&& (column[i] != '\n'))
		{
			*message = ft_strdup("Invalid map - Invalid char inside the map.");
			break ;
		}
		if (data->val_data.player > ELEMENT_MINIMUM)
		{
			*message = ft_strdup("Invalid map - Too many players.");
			break ;
		}
		if (data->val_data.exit > ELEMENT_MINIMUM)
		{
			*message = ft_strdup("Invalid map - Too many exits.");
			break ;
		}
	}
}
