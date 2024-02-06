/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:57:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/06 07:02:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_flood_fill.h"

static void	ft_rot3(t_map *map, int8_t shift);
static void	ft_flood_fill_error(t_canvas *data, char *message);

void	ft_flood_fill(t_map *map_pos, int8_t shift)
{
	if ((shift == RIGHT) && (map_pos->chr == PLAYER || map_pos->chr == FLOOR \
		|| map_pos->chr == COLL || map_pos->chr == EXIT_DOOR))
		ft_rot3(map_pos, shift);
	else if ((shift == LEFT) && (map_pos->chr == (PLAYER + ROT3) \
		|| map_pos->chr == (FLOOR + ROT3) || map_pos->chr == (COLL + ROT3) \
		|| map_pos->chr == (EXIT_DOOR + ROT3)))
		ft_rot3(map_pos, shift);
}

static void	ft_rot3(t_map *map, int8_t shift)
{
	if (shift == RIGHT)
		map->chr += ROT3;
	else if (shift == LEFT)
		map->chr -= ROT3;
	if (map->up)
		ft_flood_fill(map->up, shift);
	if (map->down)
		ft_flood_fill(map->down, shift);
	if (map->next)
		ft_flood_fill(map->next, shift);
	if (map->prev)
		ft_flood_fill(map->prev, shift);
}

void	ft_check_flood_fill(t_canvas *data, int16_t collectable, \
			int16_t exit_door)
{
	t_map	*map_temp;

	map_temp = data->map;
	while (map_temp)
	{
		if (map_temp->chr == COLL)
			collectable++;
		if (map_temp->chr == EXIT_DOOR)
			exit_door++;
		map_temp = map_temp->next;
	}
	if (collectable != 0)
		ft_flood_fill_error(data, \
			"Invalid map - Collectables has no valid path.");
	if (exit_door != 0)
		ft_flood_fill_error(data, "Invalid map - Exit has no valid path.");
}

static void	ft_flood_fill_error(t_canvas *data, char *message)
{
	ft_clean_map_lst(data->map);
	ft_output_error(message);
}
