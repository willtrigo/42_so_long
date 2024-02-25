/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 05:09:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_non_standard/ft_non_standard.h"
# include "ft_so_long.h"

void	ft_output_error_msg(char *msg);
void	ft_exit_error(void);
void	ft_output_error(char *msg);
void	ft_read_output_error(int32_t fd, char *msg);
void	ft_output_msg(char *title, char *msg, int8_t color);

#endif
