/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 05:09:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include "MLX42/MLX42.h"
# include "ft_non_standard/ft_non_standard.h"
# include "ft_so_long_bonus.h"

void	ft_output_error_msg(char *msg);
void	ft_exit_error(void);
void	ft_output_error(char *msg);
void	ft_read_output_error(int32_t fd, char *msg);
void	ft_output_msg(char *title, char *msg, int8_t color, \
			t_canvas *data);

#endif
