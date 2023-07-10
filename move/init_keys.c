/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:42:04 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:42:15 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_keys(t_keys *keys)
{
	keys->right = false;
	keys->left = false;
	keys->back = false;
	keys->forward = false;
	keys->rotate_left = false;
	keys->rotate_right = false;
	keys->esc = false;
	keys->up = false;
	keys->down = false;
}
