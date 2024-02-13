/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:45:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/11 15:10:25 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_render.h"

static void	ft_render_texture(t_canvas *data, mlx_image_t **canvas, \
	int16_t column, int16_t line);

void	ft_render_game(t_canvas *data)
{
	ft_handle_texture(data, FLOOR, data->map, INIT);
	ft_handle_texture(data, WALL, data->map, INIT);
	ft_handle_texture(data, COLL, data->map, INIT);
	ft_handle_texture(data, PLAYER, data->map, INIT);
}

void	ft_handle_texture(t_canvas *data, char canvas, t_map *map_temp, \
	int16_t i)
{
	int16_t	column;
	int16_t	line;

	line = -1;
	while (++line < data->line)
	{
		column = -1;
		while (++column < data->column)
		{
			if (canvas == FLOOR)
				ft_render_texture(data, &data->canvas_floor, column, line);
			if (canvas == WALL && map_temp->chr == WALL)
				ft_render_texture(data, &data->canvas_wall, column, line);
			else if (canvas == PLAYER && map_temp->active == TRUE)
				ft_render_texture(data, &data->canvas_player, column, line);
			else if (canvas == EXIT_DOOR && map_temp->chr == EXIT_DOOR)
				ft_render_texture(data, &data->canvas_exit, column, line);
			else if (canvas == COLL && map_temp->enable == TRUE)
				ft_render_texture(data, &data->canvas_coll, column, line);
			if (++i != data->line * data->column)
				map_temp = map_temp->next;
		}
	}
}

static void	ft_render_texture(t_canvas *data, mlx_image_t **canvas, \
	int16_t column, int16_t line)
{
	mlx_image_to_window(data->mlx, *canvas, column * data->tile_size, \
		line * data->tile_size);
}
