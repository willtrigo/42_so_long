/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:32:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/24 09:16:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

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
	if (fd <= FAIL || *buf != FLOOR)
	{
		if (fd <= FAIL)
			ft_read_output_error(fd, "Invalid map - Map file is empty.");
		else if (*buf != FLOOR)
			ft_read_output_error(fd, "Invalid map - Map file is empty.");
	}
	close(fd);
}
#include <stdio.h>
void	ft_parse_map(char *map, t_canvas *data)
{
	int32_t	fd;
	char	*buf;
	char	*map_temp;

	fd = open(map, O_RDONLY, 0666);
	if (fd <= FAIL)
		ft_read_output_error(fd, "Invalid map - Map file is corrupted.");
	buf = get_next_line(fd);
	data->map = ft_strdup("");
	while (buf)
	{
		// printf("%s", buf);
		if (data->column == COLUMN_INIT)
		{
			data->column = ft_strlen(buf);
		}
		//map_temp = malloc(sizeof(char) + ft_strlen(data->map) + BYTE);
		map_temp = data->map;
		//free(data->map);
		data->map = ft_strjoin(map_temp, buf);
		free(map_temp);
		free(buf);
		buf = get_next_line(fd);
		data->line++;
	}
	printf("%s\n", data->map);
	printf("%d - column | %d - line\n", data->column, data->line);
	close(fd);
	//free(buf);
	free(data->map);
}
