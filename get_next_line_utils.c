/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:13:27 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/23 16:08:36 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_classic(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	return (i);
}

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *buff, char *rest)
{
	char	*str;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!buff && !rest)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen_classic(buff) + ft_strlen_classic(rest)) + 1);
	if (!str)
		return (0);
	if (rest)
	{
		while (rest[i])
		{
			str[i] = rest[i];
			i++;
		}
	}
	while (buff[u])
		str[i++] = buff[u++];
	str[i] = 0;
	if (rest)
		free(rest);
	return (str);
}

char	*get_line(char *rest)
{
	char	*str;
	int		i;

	i = 0;
	if (rest[i] == 0)
		return (0);
	str = malloc(sizeof(char) * ft_strlen(rest) + 1);
	if (!str)
		return (0);
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*get_rest(char *rest)
{
	char	*str;
	int		i;
	int		u;
	int		size;

	u = 0;
	i = 0;
	size = ft_strlen_classic(rest) - ft_strlen(rest);
	if (!size)
	{
		free(rest);
		return (NULL);
	}
	str = malloc(sizeof (char) * (size + 1));
	if (!str)
		return (0);
	i = ft_strlen(rest);
	while (rest[i])
	{
		str[u] = rest[i];
		u++;
		i++;
	}
	str[u] = 0;
	free(rest);
	return (str);
}
