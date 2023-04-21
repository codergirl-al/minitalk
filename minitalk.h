/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:23:59 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/20 17:48:00 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//util functions
char	ft_convert_binary(char *binary);
int		ft_validate_client_string(const char **str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putnbr(int num);

#endif
