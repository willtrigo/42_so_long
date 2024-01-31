/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:09:27 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/31 01:10:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_lst.h"

void	ft_node_map_add(t_map **node_map, t_map *node_map_new)
{
	t_map	*node_map_temp;

	if (node_map_new)
	{
		if (!*node_map)
			*node_map = node_map_new;
		else
		{
			node_map_temp = *node_map;
			while (node_map_temp->next)
				node_map_temp = node_map_temp->next;
			node_map_temp->next = node_map_new;
		}
	}
}

t_map	*ft_node_map_new(char content)
{
	t_map	*node_map_new;

	node_map_new = ft_calloc(1, sizeof(t_map));
	if (!node_map_new)
	{
		free(node_map_new);
		return (NULL);
	}
	node_map_new->content = content;
	return (node_map_new);
}

int32_t	ft_node_map_size(t_map *node_map)
{
	int32_t	i;

	i = 0;
	while (++i && node_map)
		node_map = node_map->next;
	return (--i);
}

t_map	*ft_get_pos(t_map *map, int32_t jump)
{
	while (jump-- && map)
		map = map->next;
	return (map);
}
