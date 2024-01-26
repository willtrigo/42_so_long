/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/25 21:52:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_H
# define FT_VALIDATE_H

# include "ft_non_standard/ft_non_standard.h"
# include "ft_string.h"
# include "ft_so_long.h"

# define TRUE 1
# define FALSE 0

void	ft_is_map_valid(char *column, char **message, t_canvas *data);

#endif
