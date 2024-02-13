/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:10:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include "ft_non_standard/ft_non_standard.h"
# include "ft_so_long_bonus.h"

void	ft_output_error_message(char *message);
void	ft_exit_error(void);
void	ft_output_error(char *message);
void	ft_read_output_error(int32_t fd, char *message);
void	ft_output_message(char *title, char *message, int8_t color);

#endif
