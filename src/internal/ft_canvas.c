/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:19:02 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/25 15:24:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

void	ft_create_canvas(char *map)
{
	t_canvas	data;

	data.column = 0;
	data.line = 0;
	ft_parse_map(map, &data);
}
