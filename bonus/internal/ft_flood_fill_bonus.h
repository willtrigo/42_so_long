/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:57:13 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:09:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOOD_FILL_BONUS_H
# define FT_FLOOD_FILL_BONUS_H

# include "MLX42/MLX42.h"
# include "ft_so_long_bonus.h"
# include "ft_clean_bonus.h"

void	ft_flood_fill(t_map *map_pos, int8_t shift);
void	ft_check_flood_fill(t_canvas *data, int16_t collectable, \
			int16_t exit_door);

#endif
