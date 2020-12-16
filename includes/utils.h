/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:36:43 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:32:19 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define FIRST_WHITESPACE	9
# define LAST_WHITESPACE	13
# define SPACE				32
# define C_LONG_MAX			2147483647

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *arr, int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup_with_border(char *s1, size_t len);
void		program_arguments_checking(int argc, char **argv);

#endif
