/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:00:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/01 06:39:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 995
# define NAME_WINDOW "42sp - dande-je's so long | map - "
# define FLOOR '0'
# define WALL '1'
# define TRUE 1
# define FALSE 0
# define BYTE 1
# define RIGHT 1
# define LEFT 2
# define ROT3 3

typedef struct s_map		t_map;
struct s_map
{
	t_map	*next;
	t_map	*prev;
	t_map	*up;
	t_map	*down;
	char	chr;
	int8_t	enable;
};

typedef struct s_canvas		t_canvas;
struct s_canvas
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	mlx_texture_t	*icon;
	char			*title_window;
	char			*name;
	int32_t			column;
	int32_t			line;
	int8_t			player;
	int8_t			exit;
	int16_t			collectable;
	t_map			*map;
	t_map			*player_pos;
};

#endif
