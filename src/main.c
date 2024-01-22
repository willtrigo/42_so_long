/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:23:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "internal/ft_utils.h"
#include "internal/ft_parse_map.h"

int32_t	main(int32_t argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_output_error("Invalid So long", \
			"./so_long [path of the map]");
	ft_parse_map(argv[1]);
	exit(EXIT_SUCCESS);
}
