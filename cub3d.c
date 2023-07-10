/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:27:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 07:09:35 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	c_game	map;

	if(ac != 2)
		ft_error("Arguments Number Error!");
	parser(av, &map);
	printf("Parsing finished");
	return 0;
}
