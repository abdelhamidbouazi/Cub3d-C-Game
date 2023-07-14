/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:41:42 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:13:44 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_data *data)
{
	data->player->angle += M_ROTATE * (M_PI / 180);
	data->player->angle = fmod(data->player->angle, (M_PI * 2));
}
