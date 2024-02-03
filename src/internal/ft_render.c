/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:45:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/03 11:02:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_render.h"

static void	ft_render_floor(t_canvas *data);
static void	ft_handle_texture(t_canvas *data, char canvas, t_map *map_temp);

void	ft_render_game(t_canvas *data)
{
	data->canvas_floor = mlx_texture_to_image(data->mlx, data->texture_floor);
	data->canvas_wall = mlx_texture_to_image(data->mlx, data->texture_wall);
	mlx_resize_image(data->canvas_floor, data->tile_size, data->tile_size);
	mlx_resize_image(data->canvas_wall, data->tile_size, data->tile_size);
	ft_render_floor(data);
	ft_handle_texture(data, WALL, data->map);
}

static void	ft_render_floor(t_canvas *data)
{
	int16_t	column;
	int16_t	line;

	line = -1;
	while (++line < data->line)
	{
		column = -1;
		while (++column < data->column)
			mlx_image_to_window(data->mlx, data->canvas_floor, column \
				* (data->tile_size + 1), line * (data->tile_size + 1));
	}
}

static void	ft_handle_texture(t_canvas *data, char canvas, t_map *map_temp)
{
	int16_t	column;
	int16_t	line;
	int16_t	i;

	line = -1;
	i = 0;
	while (++line < data->line)
	{
		column = -1;
		while (++column < data->column)
		{
			if (canvas == WALL && map_temp->chr == WALL)
				mlx_image_to_window(data->mlx, data->canvas_wall, column \
					* (data->tile_size + 1), line * (data->tile_size + 1));
			if (++i != data->line * data->column)
				map_temp = map_temp->next;
		}
	}
}
