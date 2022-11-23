/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:11:01 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/23 10:13:21 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *buff, char *rest);
int		ft_strlen(char *str);
char	*get_line(char *rest);
int		check(char *tmp);
char	*get_rest(char *rest);
int	ft_strlen_classic(char *str);

#endif
