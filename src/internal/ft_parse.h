/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:32:24 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/26 00:02:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "ft_non_standard/ft_non_standard.h"
# include "ft_non_standard/ft_get_next_line.h"
# include "ft_string.h"
# include "ft_so_long.h"
# include "ft_validate.h"
# include "ft_utils.h"
# include "ft_clean.h"

# define LIMIT_ARGS 2
# define ETE ".ber"
# define ETE_LEN 4
# define BUF_SIZE 1
# define FAIL -1

void	ft_parse_arguments(int32_t argc, char *map);
void	ft_parse_map(char *map, t_canvas *data);

#endif
