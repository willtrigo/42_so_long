/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:32:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/31 01:17:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_parse.h"

static char	*ft_parse_buf(int32_t fd, char *buf, t_canvas *data);
static void	ft_build_map_lst(t_canvas *data, int32_t map_size);

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
	if (fd <= FAIL || *buf != WALL)
		ft_read_output_error(fd, "Invalid map - Map file not exist.");
	if (*buf != WALL)
		ft_read_output_error(fd, \
			"Invalid map - Map is not surrounded by walls.");
	close(fd);
}

void	ft_parse_map(char *map, t_canvas *data)
{
	int32_t	fd;
	int32_t	i;
	int32_t	map_size;
	char	*buf;

	buf = NULL;
	i = -1;
	fd = open(map, O_RDONLY, 0666);
	if (fd <= FAIL)
		ft_read_output_error(fd, "Invalid map - Map file is corrupted.");
	buf = ft_parse_buf(fd, buf, data);
	close(fd);
	data->column--;
	while (buf[++i])
		if (buf[i] != '\n')
			ft_node_map_add(&data->map, ft_node_map_new(buf[i]));
	map_size = ft_node_map_size(data->map);
	free(buf);
	ft_build_map_lst(data, map_size);
}

static char	*ft_parse_buf(int32_t fd, char *buf, t_canvas *data)
{
	char	*check_map_valid;
	char	*check_map;
	char	*check_map_temp;

	buf = get_next_line(fd);
	check_map = ft_strdup("");
	data->column = ft_strlen(buf);
	while (buf)
	{
		ft_is_map_valid(buf, &check_map_valid, data, FALSE);
		check_map_temp = check_map;
		check_map = ft_strjoin(check_map_temp, buf);
		free(check_map_temp);
		free(buf);
		if (check_map_valid)
			ft_clean_buf(fd, check_map, check_map_valid);
		buf = get_next_line(fd);
		data->line++;
	}
	ft_is_map_valid(&check_map[data->line * data->column - data->column], \
		&check_map_valid, data, TRUE);
	if (check_map_valid)
		ft_clean_buf(fd, check_map, check_map_valid);
	return (check_map);
}

static void	ft_build_map_lst(t_canvas *data, int32_t map_size)
{
	int32_t	map_pos;
	t_map	*map_init;

	map_pos = 0;
	map_init = NULL;
	if (map_size != data->column * data->line)
	{
		ft_clean_map_lst(data->map);
		ft_output_error("Invalid map - Map allocation failed.");
	}
	map_init = data->map;
	while (data->map)
	{
		data->map->down = ft_get_pos(data->map, data->column);
		if (map_pos > data->column - 2)
			data->map->up = ft_get_pos(map_init, map_pos - data->column + 1);
		if (map_pos != 0)
			data->map->prev = ft_get_pos(map_init, map_pos - 1);
		map_pos++;
		data->map = data->map->next;
	}
	data->map = map_init;
}
