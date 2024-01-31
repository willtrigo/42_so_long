/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:09:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/31 01:11:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "ft_stdlib.h"
# include "ft_so_long.h"
# include "ft_clean.h"

void	ft_node_map_add(t_map **node_map, t_map *node_map_new);
t_map	*ft_node_map_new(char content);
int32_t	ft_node_map_size(t_map *node_map);
t_map	*ft_get_pos(t_map *map, int32_t jump);

#endif
