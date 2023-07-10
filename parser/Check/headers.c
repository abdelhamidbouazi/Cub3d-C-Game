/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:00:10 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:39 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void headers(char **map, int *index)
{
    int count = 0;

    while (*index < 4 && map[*index] != NULL)
    {
        if (strncmp(map[*index], "NO ", 3) == 0
            || strncmp(map[*index], "SO ", 3) == 0
            || strncmp(map[*index], "WE ", 3) == 0
            || strncmp(map[*index], "EA ", 3) == 0)
            count++;
        (*index)++;
    }

    if (count != 4 && *index != count)
        ft_error("Check Texture In Map File !");
    if (*index == 0)
        ft_error("File is Empty!");
}
