/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:09 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/02 06:59:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_utils.h"

void	ft_output_error(char *message)
{
	ft_output_message(message);
	ft_exit_error();
}

void	ft_read_output_error(int32_t fd, char *message)
{
	close(fd);
	ft_output_message(message);
	ft_exit_error();
}

void	ft_output_message(char *message)
{
	ft_putstr_fd("\033[0;31mError", STDERR_FILENO);
	ft_putstr_fd("\n\033[0m", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_exit_error(void)
{
	exit(EXIT_FAILURE);
}
