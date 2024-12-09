/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:00:55 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 06:03:04 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_player(char p)
{
	return (p == 'N' || p == 'S' || p == 'W' || p == 'E');
}

int	check_surr2(char **line, int i, int j)
{
	if (line[i][j] == '0' || is_player(line[i][j]))
	{
		if (j == 0)
			return (0);
		if (line[i - 1][j] == ' ' ||
			line[i + 1][j] == ' ' ||
			line[i][j - 1] == ' ' ||
			line[i][j + 1] == ' ')
			return (0);
		if (line[i - 1][j] == '\0' ||
			line[i + 1][j] == '\0' ||
			line[i][j - 1] == '\0' ||
			line[i][j + 1] == '\0')
			return (0);
	}
	return (1);
}

int	check_surr(char **line, int row)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (line[i][++j])
	{
		if (line[i][j] == '0' || is_player(line[i][j]))
			return (0);
	}
	while (line[++i] && i < row - 1)
	{
		j = -1;
		while (line[i][++j])
			if (check_surr2(line, i, j) == 0)
				return (0);
	}
	j = -1;
	while (line[i][++j])
	{
		if (line[i][j] == '0' || is_player(line[i][j]))
			return (0);
	}
	return (1);
}
