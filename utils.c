/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:03 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/20 18:33:44 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** @brief converts a string into an int.
**
** @details When the number overflow at the long long
** level, the number will became negative, it returns
** 0 or -1 depending on the size. Overflow on the int
** level is handled by the casting at the end.
**
** @param str: the string that represents a number,
** multiple spaces, follow by one '-' or '+', is allowed.
** @return the int after convertion
*/
int	ft_atoi(const char *str)
{
	long	val;
	int		i;
	int		isneg;

	i = 0;
	isneg = 1;
	val = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
		*str == '\r' || *str == '\f')
	str++;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (str[i] - '0') + (10 * val);
		i++;
		if ((isneg * val) > 4294967295)
			return (-1);
		if ((isneg * val) < -4294967295)
			return (0);
		}
	if (*str == '-')
		val = val * -1;
	return (val);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putnbr(int num)
{
	int	c;

	if (num > 9) {
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9) {
		c = (('0' + num));
		write(1, &c, 1);
	}
}

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

int	ft_validate_client_string(const char **str)
{
	const char	*ptr;

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
