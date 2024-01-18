/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:45:09 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/18 03:45:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_output_error(char *str_title, char *str_message)
{
	ft_help();
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	ft_putstr_fd(str_title, STDERR_FILENO);
	ft_putstr_fd("\033[0m - ", STDERR_FILENO);
	ft_putstr_fd(str_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
