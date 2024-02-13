/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 20:11:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "internal/ft_utils_bonus.h"
#include "internal/ft_parse_bonus.h"
#include "internal/ft_canvas_bonus.h"

int32_t	main(int32_t argc, char **argv)
{
	ft_parse_arguments(argc, argv[1]);
	ft_create_canvas(argv[1]);
	exit(EXIT_SUCCESS);
}
