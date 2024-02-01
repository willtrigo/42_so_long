/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:57:19 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/01 06:39:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_flood_fill.h"

static void	ft_rot3(t_map *map, int8_t shift);

void	ft_flood_fill(t_map *map_pos, int8_t shift)
{
	if ((shift == RIGHT) && (map_pos->chr == 'P' || map_pos->chr == '0' \
		|| map_pos->chr == 'C' || map_pos->chr == 'E'))
		ft_rot3(map_pos, shift);
	else if ((shift == LEFT) && (map_pos->chr == ('P' + ROT3) \
		|| map_pos->chr == ('0' + ROT3) || map_pos->chr == ('C' + ROT3) \
		|| map_pos->chr == ('E' + ROT3)))
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
