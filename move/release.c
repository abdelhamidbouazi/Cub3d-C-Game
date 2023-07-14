/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:42:38 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:12:33 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	release(int key, t_data *data)
{
	if (key == FORWARD)
		data->keys->forward = false;
	else if (key == BACK)
		data->keys->back = false;
	else if (key == LEFT)
		data->keys->left = false;
	else if (key == RIGHT)
		data->keys->right = false;
	else if (key == ROTATE_LEFT)
		data->keys->rotate_left = false;
	else if (key == ROTATE_RIGHT)
		data->keys->rotate_right = false;
	else if (key == ESC)
		data->keys->esc = false;
	return (0);
}
