/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:59 by otangkab          #+#    #+#             */
/*   Updated: 2022/11/15 20:09:04 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
