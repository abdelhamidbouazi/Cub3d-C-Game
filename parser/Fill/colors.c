/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:02:02 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:46 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void rgb(c_color *color, char **str)
{
    color->r = ft_atoi(str[0]);
    color->g = ft_atoi(str[1]);
    color->b = ft_atoi(str[2]);
}
