/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:32:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/18 04:36:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_parse.h"

static void	ft_parse_buf(char **buf, t_canvas *data, char *check_map, \
	char *check_map_temp);
static void	ft_build_map_lst(t_canvas *data, int32_t map_size, t_map *map);
static void	ft_check_tile(t_map *map, t_canvas *data);

void	ft_parse_arguments(int32_t argc, char *map)
{
	int32_t	fd;
	int32_t	file;
	size_t	map_len;
	char	buf[BUF_SIZE];

	if (argc < LIMIT_ARGS)
		ft_output_error("Invalid so long - Map file is missing.");
	else if (argc > LIMIT_ARGS)
		ft_output_error("Invalid so long - Too many arguments.");
	map_len = ft_strlen(map);
	if (ft_strncmp(&map[map_len - ETE_LEN], ETE, ETE_LEN))
		ft_output_error("Invalid map - Extension must be .ber.");
	fd = open(map, O_RDONLY, 0666);
	file = read(fd, buf, BUF_SIZE);
	if (file && (fd <= FAIL || *buf != WALL))
		ft_read_output_error(fd, "Invalid map - Map file not exist.");
	if (*buf != WALL)
		ft_read_output_error(fd, \
			"Invalid map - Map is not surrounded by walls.");
	close(fd);
}

void	ft_parse_map(char *map, t_canvas *data)
{
	int32_t	i;
	int32_t	map_size;
	char	*buf;

	buf = NULL;
	i = -1;
	map_size = 0;
	data->val_data.fd = open(map, O_RDONLY, 0666);
	if (data->val_data.fd <= FAIL)
		ft_read_output_error(data->val_data.fd, \
			"Invalid map - Map file is corrupted.");
	ft_parse_buf(&buf, data, NULL, NULL);
	close(data->val_data.fd);
	data->val_data.column--;
	ft_validate_tile_size(data, buf);
	while (buf[++i])
		if (buf[i] != '\n')
			ft_node_map_add(&data->map, ft_node_map_new(buf[i]));
	map_size = ft_node_map_size(data->map);
	free(buf);
	ft_build_map_lst(data, map_size, data->map);
	ft_flood_fill(data->player_pos, RIGHT);
	ft_check_flood_fill(data, 0, 0);
	ft_flood_fill(data->player_pos, LEFT);
	data->player_pos->chr = '0';
}

static void	ft_parse_buf(char **buf, t_canvas *data, char *check_map, \
	char *check_map_temp)
{
	char	*check_map_valid;

	check_map_valid = NULL;
	*buf = get_next_line(data->val_data.fd);
	check_map = ft_strdup("");
	data->val_data.column = ft_strlen(*buf);
	while (*buf)
	{
		ft_is_map_valid(*buf, &check_map_valid, data, FALSE);
		check_map_temp = check_map;
		check_map = ft_strjoin(check_map_temp, *buf);
		free(check_map_temp);
		free(*buf);
		if (check_map_valid)
			ft_clean_buf(data->val_data.fd, check_map, check_map_valid);
		*buf = get_next_line(data->val_data.fd);
		data->val_data.line++;
	}
	ft_is_map_valid(&check_map[data->val_data.line * data->val_data.column \
		- data->val_data.column], &check_map_valid, data, TRUE);
	if (check_map_valid)
		ft_clean_buf(data->val_data.fd, check_map, check_map_valid);
	*buf = ft_strdup(check_map);
	free(check_map);
}

static void	ft_build_map_lst(t_canvas *data, int32_t map_size, t_map *map)
{
	int32_t	map_pos;

	map_pos = 0;
	if (map_size != data->val_data.column * data->val_data.line)
	{
		ft_clean_map_lst(data->map);
		ft_output_error("Invalid map - Map allocation failed.");
	}
	while (map)
	{
		ft_check_tile(map, data);
		map->down = ft_get_pos(map, data->val_data.column);
		if (map_pos > data->val_data.column - 2)
			map->up = ft_get_pos(data->map, map_pos - data->val_data.column);
		if (map_pos != 0)
			map->prev = ft_get_pos(data->map, map_pos - 1);
		map_pos++;
		map = map->next;
	}
}

static void	ft_check_tile(t_map *map, t_canvas *data)
{
	map->active = FALSE;
	if (map->chr == PLAYER)
	{
		map->active = TRUE;
		data->player_pos = map;
	}
	else if (map->chr == EXIT_DOOR)
	{
		map->enable = FALSE;
		data->exit_pos = map;
	}
	else if (map->chr == COLL)
		map->enable = TRUE;
}
