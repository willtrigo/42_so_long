/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/28 01:12:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_H
# define FT_VALIDATE_H

# include "ft_non_standard/ft_non_standard.h"
# include "ft_string.h"
# include "ft_so_long.h"

# define COLUMN_MINIMUM 3
# define ELEMENT_MINIMUM 1

void	ft_is_map_valid(char *column, char **message, t_canvas *data, \
			int8_t last_line);
int8_t	ft_check_wall(char *column, t_canvas *data, int8_t last_line);

#endif
