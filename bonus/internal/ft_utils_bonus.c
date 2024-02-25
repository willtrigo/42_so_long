/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:09 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 05:09:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_utils_bonus.h"

void	ft_output_error(char *msg)
{
	ft_output_error_msg(msg);
	ft_exit_error();
}

void	ft_read_output_error(int32_t fd, char *msg)
{
	close(fd);
	ft_output_error_msg(msg);
	ft_exit_error();
}

void	ft_output_error_msg(char *msg)
{
	ft_putstr_fd("\033[0;31mError", STDERR_FILENO);
	ft_putstr_fd("\n\033[0m", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_exit_error(void)
{
	exit(EXIT_FAILURE);
}

void	ft_output_msg(char *title, char *msg, int8_t color, \
			t_canvas *data)
{
	char	*msg_temp;

	if (color == GREEN)
	{
		ft_putstr_fd("\033[0;32m", STDOUT_FILENO);
		ft_putstr_fd(title, STDOUT_FILENO);
		ft_putstr_fd("\033[0m - ", STDOUT_FILENO);
		ft_putstr_fd(msg, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else if (color == CYAN)
	{
		msg_temp = ft_strjoin(title, msg);
		data->info_count = mlx_put_string(data->mlx, msg_temp, 5, HEIGHT - 27);
		free(msg_temp);
	}
}
