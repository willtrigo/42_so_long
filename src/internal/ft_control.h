/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:33:49 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/06 06:44:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROL_H
# define FT_CONTROL_H

# include "MLX42/MLX42.h"
# include "ft_non_standard/ft_non_standard.h"
# include "ft_so_long.h"
# include "internal/ft_assets.h"
# include "internal/ft_render.h"
# include "internal/ft_utils.h"

void	ft_key_hook(mlx_key_data_t key, t_canvas *data);

#endif
