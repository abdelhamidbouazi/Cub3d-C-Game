/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ciel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:01:19 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:12:29 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	floor_ciel(char **map, int *index)
{
	int	count;
	int	start;
	int	end;

	count = 0;
	start = *index;
	end = *index + count;
	while (*index < end && map[*index] != NULL)
	{
		if (ft_strncmp(map[*index], "F ", 2) == 0 || \
			ft_strncmp(map[*index], "C ", 2) == 0)
			count++;
		(*index)++;
	}
	if (*index - start != count && count != 2)
		ft_error("F or C Error !");
}
