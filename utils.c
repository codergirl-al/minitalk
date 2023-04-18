/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:03 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/18 22:34:26 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** Convert a binary string to an ASCII character.
** binary: the binary string to convert (8 bits)
** returns: the corresponding ASCII character
*/
char	ft_convert_binary(char *binary)
{
	char	res;
	int		index;

	index = -1;
	res = 0;
	while (binary[++index] != '\0')
	{
		if (binary[index] == '1')
			res = res | (1 << (7 - index));
	}
	return (res);
}

/*
** Check if the input pointer-to-a-string contains digits
** If so, return 0;
** else, continue.
*/

int ft_validate_client_string(const char **str)
{
	const char *ptr;

	ptr = *str;
	if (!str)
		return (0);
	if (*ptr == '-')
		ptr++;
	while (*ptr != '\0')
	{
		if (!ft_isdigit(*ptr))
			return (0);
		ptr++;
	}
	return (1);
}
