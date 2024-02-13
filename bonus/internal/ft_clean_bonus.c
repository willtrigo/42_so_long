/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:57:47 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:08:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_clean_bonus.h"

static void	ft_clean_so_long_assets(t_canvas *data);
static void	ft_clean_so_long_struct(t_canvas *data);

void	ft_clean(t_canvas *data)
{
	ft_clean_so_long_assets(data);
	mlx_delete_image(data->mlx, data->canvas_wall);
	mlx_delete_image(data->mlx, data->canvas_floor);
	mlx_delete_image(data->mlx, data->canvas_coll);
	mlx_delete_image(data->mlx, data->canvas_exit);
	mlx_delete_image(data->mlx, data->canvas_player);
	ft_clean_so_long_struct(data);
}

void	ft_clean_buf(int32_t fd, char *check_map, char *message)
{
	close(fd);
	free(check_map);
	ft_output_error_message(message);
	free(message);
	ft_exit_error();
}

void	ft_clean_map_lst(t_map *map_lst)
{
	t_map	*map_lst_temp;

	map_lst_temp = NULL;
	while (map_lst->next)
	{
		map_lst_temp = map_lst->next;
		free(map_lst);
		map_lst = map_lst_temp;
	}
	free(map_lst);
	map_lst = NULL;
}

static void	ft_clean_so_long_assets(t_canvas *data)
{
	mlx_delete_texture(data->texture_wall);
	mlx_delete_texture(data->texture_floor);
	mlx_delete_texture(data->texture_coll);
	mlx_delete_texture(data->texture_exit);
	mlx_delete_texture(data->texture_player);
	mlx_delete_texture(data->icon);
}

static void	ft_clean_so_long_struct(t_canvas *data)
{
	ft_clean_map_lst(data->map);
}
