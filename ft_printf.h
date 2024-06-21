/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:26 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/11 19:08:11 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>		// to use 'printf'			remove before submission!!!
# include <limits.h>	// to use INT_MAX and alike	remove before submission!!!
# include <unistd.h>	// to use 'write'
# include <stdlib.h>	// to allocate/free heap memory
# include <stdarg.h>	// to use variadic functions

int		ft_int_hex_2_dec(int original);
void	ft_print_dec(int input, int *rv);
void	ft_print_hex(unsigned long int input, int *rv, char c);
int		ft_printf(const char *c, ...);
void	ft_putchar_rv(char input, int *rv);
void	ft_putnbr_rv(int n, int *rv);
void	ft_putstr_rv(char *input, int *rv);
void	ft_putunsign_rv(unsigned int n, int *rv);

//int		ft_char_hex_2_dec(char *original);
//int		ft_dec_2_int_hex(int original);
//size_t	ft_intlen(int n);
//int		ft_isdigit(int c);
//void	ft_print_char_hex(char *original, int *rv);
//void	ft_print_hex(char *original, int fd);
//void	ft_print_hex(unsigned int input, int *rv);
//void	ft_putchar_fd(char c, int fd);
//void	ft_putnbr_fd(int n, int fd);
//void	ft_putstr_fd(char *s, int fd);
//size_t	ft_strlen(const char *str);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
