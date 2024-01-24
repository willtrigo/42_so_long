/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:09 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/24 06:41:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_utils.h"

void	ft_output_error(char *str_message)
{
	ft_putstr_fd("\033[0;31mError", STDERR_FILENO);
	ft_putstr_fd("\n\033[0m", STDERR_FILENO);
	ft_putstr_fd(str_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_read_output_error(int32_t fd, char *str_message)
{
	close(fd);
	ft_output_error(str_message);
}
