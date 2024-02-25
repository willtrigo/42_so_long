/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:09 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 04:24:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_utils_bonus.h"

void	ft_output_error(char *message)
{
	ft_output_error_message(message);
	ft_exit_error();
}

void	ft_read_output_error(int32_t fd, char *message)
{
	close(fd);
	ft_output_error_message(message);
	ft_exit_error();
}

void	ft_output_error_message(char *message)
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

void	ft_output_message(char *title, char *message, int8_t color, \
			t_canvas *data)
{
	char	*message_temp;

	if (color == GREEN)
	{
		ft_putstr_fd("\033[0;32m", STDOUT_FILENO);
		ft_putstr_fd(title, STDOUT_FILENO);
		ft_putstr_fd("\033[0m - ", STDOUT_FILENO);
		ft_putstr_fd(message, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else if (color == CYAN)
	{
		message_temp = ft_strjoin(title, message);
		data->info_count = mlx_put_string(data->mlx, message_temp, 5, HEIGHT - 27);
		free(message_temp);
	}
}
