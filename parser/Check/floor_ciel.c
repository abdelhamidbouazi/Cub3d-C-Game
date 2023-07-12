/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ciel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:01:19 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/12 07:36:40 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void floor_ciel(char **map, int *index)
{
    int count = 0;
    int start = *index;
    int end = *index + count;

    while (*index < end && map[*index] != NULL)
    {
        if (ft_strncmp(map[*index], "F ", 2) == 0 || ft_strncmp(map[*index], "C ", 2) == 0)
            count++;
        (*index)++;
    }
    if (*index - start != count && count != 2)
        ft_error("F or C Error !");
}

