/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 05:09:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_BONUS_H
# define FT_VALIDATE_BONUS_H

# include "ft_non_standard/ft_non_standard.h"
# include "ft_string.h"
# include "ft_so_long_bonus.h"
# include "ft_utils_bonus.h"

# define COLUMN_MINIMUM 3
# define ELEMENT_MINIMUM 1

void	ft_is_map_valid(char *column, char **msg, t_canvas *data, \
			int8_t last_line);
int8_t	ft_check_wall(char *column, t_canvas *data, int8_t last_line);
void	ft_validate_tile_size(t_canvas *data, char *buf);

#endif
