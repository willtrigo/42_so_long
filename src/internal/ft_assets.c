/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 04:02:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/06 05:17:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_assets.h"

static void	ft_load_assets(t_canvas *data, mlx_texture_t **texture, \
	mlx_image_t **canvas, char *path);

void	ft_handle_assets(t_canvas *data)
{
	data->icon = mlx_load_png("./textures/assets/42_icon.png");
	ft_load_assets(data, &data->texture_floor, &data->canvas_floor, \
		"./textures/floor.png");
	ft_load_assets(data, &data->texture_wall, &data->canvas_wall, \
		"./textures/wall.png");
	ft_load_assets(data, &data->texture_coll, &data->canvas_coll, \
		"./textures/collectable.png");
	ft_load_assets(data, &data->texture_exit, &data->canvas_exit, \
		"./textures/exit.png");
	ft_load_assets(data, &data->texture_player, &data->canvas_player, \
		"./textures/player.png");
}

void	ft_reload_assets(t_canvas *data, mlx_texture_t **texture, \
	mlx_image_t **canvas)
{
	*canvas = mlx_texture_to_image(data->mlx, *texture);
	mlx_resize_image(*canvas, data->tile_size, data->tile_size);
}

static void	ft_load_assets(t_canvas *data, mlx_texture_t **texture, \
	mlx_image_t **canvas, char *path)
{
	*texture = mlx_load_png(path);
	*canvas = mlx_texture_to_image(data->mlx, *texture);
	mlx_resize_image(*canvas, data->tile_size, data->tile_size);
}
