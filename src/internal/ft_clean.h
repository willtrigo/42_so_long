/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:57:38 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/28 00:36:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLEAN_H
# define FT_CLEAN_H

# include "ft_stdlib.h"
# include "ft_so_long.h"
# include "internal/ft_utils.h"

void	ft_clean(t_canvas *data);
void	ft_clean_buf(int32_t fd, char *check_map, char *message);

#endif
