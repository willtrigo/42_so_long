/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/24 00:35:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "internal/ft_utils.h"
#include "internal/ft_parse.h"
#include "internal/ft_canvas.h"

int32_t	main(int32_t argc, char **argv)
{
	ft_parse_arguments(argc, argv[1]);
	ft_create_canvas(argv[1]);
	exit(EXIT_SUCCESS);
}
