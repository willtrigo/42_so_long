/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:19:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/31 01:16:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	ft_create_canvas(char *map)
{
	t_canvas	data;

	data.column = 0;
	data.line = 0;
	data.player = 0;
	data.exit = 0;
	data.collectable = 0;
	data.map = NULL;
	ft_parse_map(map, &data);
	ft_clean_map_lst(data.map);
}
