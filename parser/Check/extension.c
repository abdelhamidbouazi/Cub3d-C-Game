/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:05:02 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:16:32 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int extension(char *arg)
{
	int len;

	len = strlen(arg);
	if (arg[len - 1] == 'b' && arg[len - 2] == 'u' && \
		arg[len - 3] == 'c' && arg[len - 4] == '.')
			return 0;
	else
		ft_error("Bad extension !");
	return 0;
}
