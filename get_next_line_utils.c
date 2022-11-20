/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:52:53 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/20 18:51:39 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	return (i);
}

char	*ft_get_line(char *buff, char *tmp)
{
	int	i;
	int	u;
	char	*str;

	u = 0;
	i = 0;
	str = malloc (sizeof (char) * (ft_strlen(buff) + ft_strlen(tmp)) + 1);
	if (!str)
		return (0);
	if (tmp)
	{	
		while (tmp[i] != 0)
		{
			str[i] = tmp[i];
			i++;
		}
	}
	while (buff[u] != '\n' && buff[u])
	{
		str[i] = buff[u];
		i++;
		u++;
	}
	if (buff[u])
		str[i++] = buff[u];
	str[i] = 0;
	return (str);
}

int	ft_strchr(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != 0)
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

char	*recuprest(char *buff)
{
	int	i;
	int	j;
	int	k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	while(buff[i] != '\n')
		i++;
	if (buff[i])
		i++;
	while (buff[i + k])
		k++;
	if (!k)
		return (0);
	str = malloc (sizeof (char) * k + 1);
	if (!str)
		return (0);
	str[k] = 0;
	while (buff[i] != 0)
	{
		str[j] = buff[i];
		j++;
		i++;
	}
	return (str);
}
