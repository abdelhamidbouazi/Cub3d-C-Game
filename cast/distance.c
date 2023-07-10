/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:38:58 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:39:16 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(double xplayer, double xray, double yplayer, double yray)
{
	double	result;
	double sum1;
	double sum2;

	sum1 = pow(xray - xplayer, 2);
	sum2 = pow(yray - yplayer, 2);
	result = sqrt(sum1 + sum2);
	return (result);
}
