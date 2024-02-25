/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:45:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 01:16:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_BONUS_H
# define FT_RENDER_BONUS_H

# include "MLX42/MLX42.h"
# include "ft_so_long_bonus.h"
# include "internal/ft_utils_bonus.h"

# define INIT 0

void	ft_handle_time(void *param);
void	ft_render_game(t_canvas *data);
void	ft_handle_texture(t_canvas *data, char canvas, t_map *map_temp, \
	int16_t i);

#endif
