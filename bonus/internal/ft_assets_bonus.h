/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 04:01:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:07:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASSETS_BONUS_H
# define FT_ASSETS_BONUS_H

# include "MLX42/MLX42.h"
# include "ft_so_long_bonus.h"

void	ft_handle_assets(t_canvas *data);
void	ft_reload_assets(t_canvas *data, mlx_texture_t **texture, \
	mlx_image_t **canvas);

#endif
