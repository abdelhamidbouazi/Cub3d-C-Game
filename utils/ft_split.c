/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:25:40 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:39:08 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	is_found(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_wc(char *str, char *s)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!is_found(str[i], s))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

char	*ft_strdup2(char *str, int *i, char *s)
{
	char	*word;
	int		len;
	int		j;

	j = *i;
	len = 0;
	while (str[j] && !is_found(str[j++], s))
		len++;
	word = (char *) malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (str[*i])
	{
		if (!is_found(str[*i], s))
		{
			word[j++] = str[*i];
			(*i)++;
		}
		else
			break ;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *s)
{
	char	**arr_str;
	int		i;
	int		words;
	int		w_i;

	i = 0;
	w_i = 0;
	words = ft_wc(str, s);
	arr_str = (char **) malloc((words + 1) * 8);
	if (!arr_str)
		return (NULL);
	while (w_i < words)
	{
		while (is_found(str[i], s) && str[i])
			if (!str[i++])
				break ;
		arr_str[w_i] = ft_strdup2(str, &i, s);
		if (!arr_str[w_i])
			return (malloc_error(arr_str));
		w_i++;
	}
	arr_str[words] = 0;
	return (arr_str);
}
