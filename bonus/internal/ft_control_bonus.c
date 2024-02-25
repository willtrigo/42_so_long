/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:36:59 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/25 02:29:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_control_bonus.h"

static void	ft_handle_player_move(t_canvas *data, t_map *player_pos);
static void	ft_check_collectable(t_canvas *data, t_map *player_pos);
static void	ft_check_exit(t_canvas *data, t_map *player_pos);

void	ft_key_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
	if (key.key == MLX_KEY_W && !data->val_data.render \
		&& data->player_pos->up->chr != WALL)
		ft_handle_player_move(data, data->player_pos->up);
	if (key.key == MLX_KEY_S && !data->val_data.render \
		&& data->player_pos->down->chr != WALL)
		ft_handle_player_move(data, data->player_pos->down);
	if (key.key == MLX_KEY_D && !data->val_data.render \
		&& data->player_pos->next->chr != WALL)
		ft_handle_player_move(data, data->player_pos->next);
	if (key.key == MLX_KEY_A && !data->val_data.render \
		&& data->player_pos->prev->chr != WALL)
		ft_handle_player_move(data, data->player_pos->prev);
}

static void	ft_handle_player_move(t_canvas *data, t_map *player_pos)
{
	char	*count_move;

	data->val_data.render = RENDER_ON;
	count_move = ft_itoa(++data->val_data.move);
	mlx_delete_image(data->mlx, data->info_count);
	ft_output_message("Number of movements - ", count_move, CYAN, data);
	free(count_move);
	ft_check_collectable(data, player_pos);
	ft_check_exit(data, player_pos);
	player_pos->active = TRUE;
	data->player_pos->active = FALSE;
	data->player_pos = player_pos;
	mlx_delete_image(data->mlx, data->canvas.player);
	ft_reload_assets(data, &data->canvas.texture_player, &data->canvas.player);
	ft_handle_texture(data, PLAYER, data->map, INIT);
	data->time.delay = mlx_get_time() + DELAY;
}

static void	ft_check_collectable(t_canvas *data, t_map *player_pos)
{
	if (player_pos->chr == COLL && player_pos->enable)
	{
		data->val_data.coll--;
		player_pos->enable = FALSE;
		mlx_delete_image(data->mlx, data->canvas.coll);
		ft_reload_assets(data, &data->canvas.texture_coll, &data->canvas.coll);
		ft_handle_texture(data, COLL, data->map, INIT);
	}
	if (!data->val_data.coll)
	{
		data->exit_pos->enable = TRUE;
		ft_reload_assets(data, &data->canvas.texture_exit, &data->canvas.exit);
		ft_handle_texture(data, EXIT_DOOR, data->map, INIT);
	}
}

static void	ft_check_exit(t_canvas *data, t_map *player_pos)
{
	if (data->exit_pos->enable && player_pos->chr == EXIT_DOOR)
	{
		ft_output_message("Humanity restored", "You won.", GREEN, data);
		mlx_close_window(data->mlx);
		return ;
	}
}
