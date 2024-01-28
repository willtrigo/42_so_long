/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:57:47 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/28 03:02:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_clean.h"

static void	ft_clean_so_long_struct(t_canvas *data);

void	ft_clean(t_canvas *data)
{
	ft_clean_so_long_struct(data);
	mlx_delete_image(data->mlx, data->canvas);
}

void	ft_clean_buf(int32_t fd, char *check_map, char *message)
{
	close(fd);
	free(check_map);
	ft_output_message(message);
	free(message);
	ft_exit_error();
}

static void	ft_clean_so_long_struct(t_canvas *data)
{
	free(data->map);
}
