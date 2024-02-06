/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:19:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/06 04:52:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	ft_create_canvas(char *map)
{
	t_canvas	data;

	data.column = 0;
	data.line = 0;
	data.player = 0;
	data.exit = 0;
	data.coll = 0;
	data.tile_size = 40;
	data.move = 0;
	data.map = NULL;
	ft_parse_map(map, &data);
	data.mlx = mlx_init(1920, 1080, "42sp - dande-je's so_long", false);
	ft_handle_assets(&data);
	ft_render_game(&data);
	mlx_set_icon(data.mlx, data.icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_loop(data.mlx);
	ft_clean(&data);
	mlx_terminate(data.mlx);
}
