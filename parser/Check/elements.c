/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:09:40 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:12:20 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	elements(char **map)
{
	int	i;

	i = 0;
	while (map[i] && ft_strcmp(map[i], "\n") == 0)
		i++;
	headers(map, &i);
	while (map[i] && ft_strcmp(map[i], "\n") == 0)
		i++;
	floor_ciel(map, &i);
	while (map[i] && ft_strcmp(map[i], "\n") == 0)
		i++;
}
