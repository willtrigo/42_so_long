/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:45:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/18 04:10:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_render.h"

static void	ft_handle_texture_bg(t_canvas *data);
static void	ft_render_texture(t_canvas *data, mlx_image_t **canvas, \
	int16_t column, int16_t line);

void	ft_handle_time(void *param)
{
	t_canvas	*data;

	data = (t_canvas *)param;
	if (mlx_get_time() > data->time.delay)
		data->val_data.render = RENDER_OFF;
}

void	ft_render_game(t_canvas *data)
{
	ft_handle_texture_bg(data);
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
	while (++line < data->val_data.line)
	{
		column = -1;
		while (++column < data->val_data.column)
		{
			if (canvas == FLOOR)
				ft_render_texture(data, &data->canvas.floor, column, line);
			if (canvas == WALL && map_temp->chr == WALL)
				ft_render_texture(data, &data->canvas.wall, column, line);
			else if (canvas == PLAYER && map_temp->active == TRUE)
				ft_render_texture(data, &data->canvas.player, column, line);
			else if (canvas == EXIT_DOOR && map_temp->chr == EXIT_DOOR)
				ft_render_texture(data, &data->canvas.exit, column, line);
			else if (canvas == COLL && map_temp->enable == TRUE)
				ft_render_texture(data, &data->canvas.coll, column, line);
			if (++i != data->val_data.line * data->val_data.column)
				map_temp = map_temp->next;
		}
	}
}

static void	ft_handle_texture_bg(t_canvas *data)
{
	int16_t	column;
	int16_t	line;

	line = -1;
	while (++line <= HEIGHT / TILE_SIZE_MAX)
	{
		column = -1;
		while (++column < WIDTH / TILE_SIZE_MAX)
			mlx_image_to_window(data->mlx, data->canvas.bg, column \
				* TILE_SIZE_MAX, line * TILE_SIZE_MAX);
	}
}

static void	ft_render_texture(t_canvas *data, mlx_image_t **canvas, \
	int16_t column, int16_t line)
{
	mlx_image_to_window(data->mlx, *canvas, column * data->val_data.tile_size, \
		line * data->val_data.tile_size);
}
