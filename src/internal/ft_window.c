/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:55:50 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/09 20:39:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_window.h"

void	ft_set_window_size(t_canvas *data)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "42sp - dande-je's so_long", false);
	mlx_set_window_limit(data->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
}
