/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 04:02:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/04 00:49:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_assets.h"

void	ft_load_assets(t_canvas *data)
{
	data->icon = mlx_load_png("./textures/assets/42_icon.png");
	data->texture_floor = mlx_load_png("./textures/floor.png");
	data->texture_wall = mlx_load_png("./textures/wall.png");
	data->texture_coll = mlx_load_png("./textures/collectable.png");
	data->texture_exit = mlx_load_png("./textures/exit.png");
	data->texture_player = mlx_load_png("./textures/player.png");
}
