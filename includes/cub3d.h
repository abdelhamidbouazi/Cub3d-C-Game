/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:34:55 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 07:30:07 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
// #include <mlx.h>
#include <stdlib.h>
# include <fcntl.h>

#include <string.h>
#include <stdio.h>


# define BUFFER_SIZE 1


typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
}				t_key;


typedef struct t_color {
	int r;
	int g;
	int b;
} c_color;


typedef struct t_map {
	int		fd;
	char	**map;
	int		i;
	char	*tmp;
	int		line;
	char	*tmp2;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		col;
	int		row;
	c_color	floor;
	c_color	ciel;
} c_map;

typedef struct t_game {
	c_map	map;

} c_game;

// Parsing
void parser(char **arg, c_game *map);
// Check
void	colors(c_game *game);
int is_valid_color(c_color color);
void	elements(char **map);
int		extension(char *arg);
void	floor_ciel(char **map, int *index);
void	headers(char **map, int *index);
int		is_texture_missing(const char *texture_path);
// Fill
void	rgb(c_color *color, char **str);
void	textures(c_game *game);
// Read
char	**read_map(char	**av);
int		num_of_lines(char **av);
char	**read_map(char	**av);
// Utils
void free_splt(char **tab);




// utils
void ft_error(char *err);
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup2(char *str, int *i, char *s);
char	*ft_strndup(char *s1, int n);
int	ft_atoi(const char *str);
char	**ft_split(char *str, char *s);
char	*ft_strndup(char *s1, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Get Next Line
char	*ft_read(char *leftxt, int fd);
char	*ft_get_line(char	*leftxt);
char	*ft_stock(char *leftxt);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);


#endif
