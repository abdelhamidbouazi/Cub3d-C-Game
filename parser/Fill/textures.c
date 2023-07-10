/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:41:30 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:50 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void textures(c_game *game)
{
    int i = 0;

    while (i < 4)
    {
        char **split = ft_split(game->map.map[i], ", \n");

        if (!split[0])
        {
            free_splt(split);
            return;
        }
        if (ft_strcmp(split[0], "NO") == 0)
            game->map.no = ft_strdup(split[1]);
        else if (ft_strcmp(split[0], "SO") == 0)
            game->map.so = ft_strdup(split[1]);
        else if (ft_strcmp(split[0], "EA") == 0)
            game->map.ea = ft_strdup(split[1]);
        else if (ft_strcmp(split[0], "WE") == 0)
            game->map.we = ft_strdup(split[1]);

        free_splt(split);
        i++;
    }
    if (is_texture_missing(game->map.no) ||
        is_texture_missing(game->map.so) ||
        is_texture_missing(game->map.ea) ||
        is_texture_missing(game->map.we))
    {
        ft_error("Texture not found!!");
    }
}
