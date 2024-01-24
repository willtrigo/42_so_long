/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:19:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/24 08:58:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	ft_create_canvas(char *map)
{
	t_canvas	data;

	data.column = COLUMN_INIT;
	data.line = 0;
	ft_parse_map(map, &data);
}
