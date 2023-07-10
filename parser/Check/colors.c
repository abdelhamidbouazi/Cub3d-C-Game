/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 03:41:32 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:14 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void colors(c_game *game)
{
    int i;

    i = 0;
    while (game->map.map[i] != NULL)
    {
        char **split = ft_split(game->map.map[i], ", \n");
        if (split[0])
        {
            if (ft_strcmp(split[0], "F") == 0)
                rgb(&game->map.floor, split + 1);
            else if (ft_strcmp(split[0], "C") == 0)
                rgb(&game->map.ciel, split + 1);
        }
        free_splt(split);
        i++;
    }
    if (!is_valid_color(game->map.ciel))
        ft_error("Ciel color should be between 0 and 255");
    if (!is_valid_color(game->map.floor))
        ft_error("Floor color should be between 0 and 255");
}

int is_valid_color(c_color color)
{
    return (color.r >= 0 && color.r <= 255 &&
            color.g >= 0 && color.g <= 255 &&
            color.b >= 0 && color.b <= 255);
}
