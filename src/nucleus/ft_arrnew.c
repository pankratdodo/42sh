/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:03:11 by qmartina          #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

char	**ft_arrnew(size_t size)
{
	char		**arr;
	size_t		i;

	if (!(arr = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		arr[i] = NULL;
		i++;
	}
	return (arr);
}
