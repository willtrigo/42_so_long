/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:45:07 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/06 04:12:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "MLX42/MLX42.h"
# include "ft_so_long.h"

# define INIT 0

void	ft_render_game(t_canvas *data);
void	ft_handle_texture(t_canvas *data, char canvas, t_map *map_temp, \
	int16_t i);

#endif
