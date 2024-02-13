/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:57:38 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:08:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLEAN_BONUS_H
# define FT_CLEAN_BONUS_H

# include "ft_stdlib.h"
# include "ft_so_long_bonus.h"
# include "internal/ft_utils_bonus.h"

void	ft_clean(t_canvas *data);
void	ft_clean_buf(int32_t fd, char *check_map, char *message);
void	ft_clean_map_lst(t_map *map_lst);

#endif
