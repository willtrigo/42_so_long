/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:19:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/18 03:32:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_canvas.h"

static void	ft_val_data_init(t_canvas *data);

void	ft_create_canvas(char *map)
{
	t_canvas	data;

	ft_val_data_init(&data);
	data.map = NULL;
	ft_parse_map(map, &data);
	mlx_set_setting(MLX_MAXIMIZED, true);
	data.mlx = mlx_init(WIDTH, HEIGHT, "42sp - dande-je's so_long", true);
	ft_handle_assets(&data);
	data.val_data.render = RENDER_ON;
	data.time.delay = 0.0;
	ft_render_game(&data);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_loop_hook(data.mlx, &ft_handle_time, &data);
	mlx_loop(data.mlx);
	ft_clean(&data);
	mlx_terminate(data.mlx);
}

static void	ft_val_data_init(t_canvas *data)
{
	data->val_data.column = 0;
	data->val_data.line = 0;
	data->val_data.player = 0;
	data->val_data.exit = 0;
	data->val_data.coll = 0;
	data->val_data.tile_size = TILE_SIZE_MAX;
	data->val_data.move = 0;
	data->val_data.fd = 0;
}
