/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/25 22:30:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_validate.h"

static int32_t	ft_is_map_proportion(char *column, t_canvas *data);

void	ft_is_map_valid(char *column, char **message, t_canvas *data)
{
	if (!ft_is_map_proportion(column, data))
		*message = ft_strdup("Invalid map - Map doesn't have proportion.");
}

static int32_t	ft_is_map_proportion(char *column, t_canvas *data)
{
	if ((size_t)data->column < 5)
		return (FALSE);
	else if ((size_t)data->column != ft_strlen(column))
		return (FALSE);
	return (TRUE);
}
