/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:41:45 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/09 19:43:25 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rotate_left(t_data *data)
{
	data->player->angle -= M_ROTATE * (M_PI/180);
	data->player->angle = fmod(data->player->angle,(M_PI * 2));
}
