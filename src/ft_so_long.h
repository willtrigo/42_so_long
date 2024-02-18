/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:00:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/18 03:23:28 by dande-je         ###   ########.fr       */
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
# define PLAYER 'P'
# define COLL 'C'
# define EXIT_DOOR 'E'
# define TILE_SIZE_16 16
# define TILE_SIZE_32 32
# define TILE_SIZE_64 54
# define TRUE 1
# define FALSE 0
# define BYTE 1
# define RIGHT 1
# define LEFT 2
# define UP 3
# define DOWN 4
# define ROT3 3
# define CYAN 0
# define GREEN 2
# define DELAY 0.13
# define RENDER_ON 0X01
# define RENDER_OFF 0X00

typedef struct s_map		t_map;
struct s_map
{
	t_map	*next;
	t_map	*prev;
	t_map	*up;
	t_map	*down;
	char	chr;
	int8_t	enable;
	int8_t	active;
};

typedef struct s_image		t_image;
struct s_image
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*coll;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_coll;
};

typedef struct s_validation	t_validation;
struct s_validation
{
	double	delay;
	int32_t	fd;
	int32_t	column;
	int32_t	line;
	int32_t	move;
	int16_t	coll;
	int8_t	tile_size;
	int8_t	player;
	int8_t	exit;
	int8_t	render;
};

typedef struct s_time		t_time;
struct s_time
{
	double	delay;
};

typedef struct s_canvas		t_canvas;
struct s_canvas
{
	mlx_t			*mlx;
	mlx_texture_t	*icon;
	t_image			canvas;
	t_validation	val_data;
	t_time			time;
	t_map			*map;
	t_map			*player_pos;
	t_map			*exit_pos;
};

#endif
