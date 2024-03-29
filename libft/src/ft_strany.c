/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:08:48 by ikarjala          #+#    #+#             */
/*   Updated: 2023/01/20 17:08:53 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return pointer to first instance of ANY character in list
 * appearing in the string cp.
*/
char	*ft_strany(char *cp, const char *list)
{
	char	*listp;

	while (*cp)
	{
		listp = (char *)(list);
		while (*listp)
		{
			if (*cp == *listp)
				return (cp);
			listp ++;
		}
		cp ++;
	}
	return (NULL);
}

/* TODO: this can be somewhat optimized similiarly to strchr with magic bits
*/
