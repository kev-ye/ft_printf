/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:50:14 by kaye              #+#    #+#             */
/*   Updated: 2020/11/24 23:54:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>

t_flag  ft_init_flag(void)
{
    t_flag flag;

    flag.minus = 0;
    flag.prec = -1;
    flag.star = 0;
    flag.type = 0;
    flag.width = 0;
    flag.zero = 0;
    return (flag);
}

int     ft_vprintf(const char *format, va_list arg)
{
    int i;
    int count;
    t_flag flag;
    
    i = 0;
    count = 0;
    flag = ft_init_flag();
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i = ft_parse_flags(format, ++i, &flag, arg);
            if (ft_type(format[i]))
                count += ft_parse(flag.type, arg, flag);
        }
        else if (format[i] != '%')
            count += ft_putchar_pf(format[i]);
        i++;
    }
    return (count);
}

int     ft_printf(const char *format, ...)
{
    va_list arg;
    int i;

    va_start(arg, format);
    i = ft_vprintf(format, arg);
    va_end(arg);
    return (i);
}

int main()
{
    void *p;
    int i;
    int count_ft_pf;
    int count_pf;

    // count_ft_pf = ft_printf("test type c : ==> [%c] <==\n", 'c');
    // count_pf = printf("real printf : ==> [%c] <==\n", 'c');
    // printf("============================================\n");
    // printf("ft_printf : %d || printf : %d\n", count_ft_pf, count_pf);
    // printf("============================================\n\n");

    // count_ft_pf = ft_printf("test type s : ==> [%s] <==\n", "test");
    // count_pf = printf("real printf : ==> [%s] <==\n", "test");
    // printf("============================================\n");
    // printf("ft_printf : %d || printf : %d\n", count_ft_pf, count_pf);
    // printf("============================================\n\n");

    // ft_printf("test type p : ==> %p <==\n", p);
    // printf("real printf : ==> %p <==\n", p);
    // printf("============================================\n\n");

    count_ft_pf = ft_printf("test type d : ==> [%-*10d] <==\n", -6, -10);
    count_pf = printf("real printf : ==> [%-*10d] <==\n", -6, -10);
    printf("============================================\n");
    printf("ft_printf : %d || printf : %d\n", count_ft_pf, count_pf);
    printf("============================================\n\n");

    // ft_printf("test type i : ==> %i <==\n", 42);
    // printf("real printf : ==> %i <==\n", 42);
    // printf("============================================\n\n");
    
    // ft_printf("test type u : ==> %u <==\n", 42);
    // printf("real printf : ==> %u <==\n", 42);
    // printf("============================================\n\n");

    // ft_printf("test type x : ==> %x <==\n", -1);
    // printf("real printf : ==> %x <==\n", -1);
    // printf("============================================\n\n");

    // ft_printf("test type X : ==> %X <==\n", 2147483647);
    // printf("real printf : ==> %X <==\n", 2147483647);
    // printf("============================================\n\n");

    // ft_printf("test type %% : ==> %% <==\n");
    // printf("real printf : ==> %% <==\n");
    // printf("============================================\n\n");

    return (0);
}