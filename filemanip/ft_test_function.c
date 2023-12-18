/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:07:14 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/18 14:27:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/*
 * Tests integer-returning functions with a single integer argument.
 * Handles special values like NULL, INT_MIN, INT_MAX, and compares libc and ft function results.
 */

void ft_inttest_for_int(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int result; 
    int ft_result;
    int value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = 0;
    else if (!ft_strncmp("INT_MIN", lst->test_values[0], 7))
        value = INT_MIN;
    else if (!ft_strncmp("INT_MAX", lst->test_values[0], 7))
       value = INT_MAX;
    else
        value = ft_atoi(ft_testfile_option_format(lst->test_values[0]));
    result = ft_inttester_int(libc_func, value);
    ft_result = ft_inttester_int(ft_func, value);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == SEGFAULT && ft_result == SEGFAULT)
        printf("%s: Segfaults as expected!\n", lst->title);
    if (ft_result != result)
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result == SEGFAULT)
            printf("SEGFAULT\n\tlibcvalue: ");
        else
            printf("%i\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%i\n", result);
    }
}

/*
 * Tests integer-returning functions with a single string argument.
 * Handles NULL inputs and compares the results from libc and ft implementations.
 */

void ft_inttest_for_str(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    char    *value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = NULL;
    else
        value = ft_testfile_option_format(lst->test_values[0]);
    result = ft_inttester_str(libc_func, value);
    ft_result = ft_inttester_str(ft_func, value);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == SEGFAULT && ft_result == SEGFAULT)
        printf("%s: Segfaults as expected!\n", lst->title);
    if (ft_result != result)
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result == SEGFAULT)
            printf("SEGFAULT\n\tlibcvalue: ");
        else
            printf("%i\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%i\n", result);
    }
}

/*
 * Tests integer-returning functions with two void pointers and a size_t argument.
 * Handles NULL inputs for the void pointers and compares libc and ft function results.
 */

void ft_inttest_for_vvz(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    void    *value1;
    void    *value2;
    size_t  value3;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value1 = NULL;
    else
        value1 = ft_testfile_option_format(lst->test_values[0]);
    if (!ft_strncmp("NULL", lst->test_values[1], 4))
        value2 = NULL;
    else
        value2 = ft_testfile_option_format(lst->test_values[1]);
    value3 = ft_atoi(ft_testfile_option_format(lst->test_values[2]));
    result = ft_inttester_vvz(libc_func, value1, value2, value3);
    ft_result = ft_inttester_vvz(ft_func, value1, value2, value3);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == SEGFAULT && ft_result == SEGFAULT)
        printf("%s: Segfaults as expected!\n", lst->title);
    if (ft_result != result)
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result == SEGFAULT)
            printf("SEGFAULT\n\tlibcvalue: ");
        else
            printf("%i\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%i\n", result);
    }
}

/* 
 * Tests integer-returning functions with two strings and a size_t argument.
 * Handles NULL inputs for the strings and compares libc and ft function results.
 */

void ft_inttest_for_ssz(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    char    *value1;
    char    *value2;
    size_t  value3;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value1 = NULL;
    else
        value1 = ft_testfile_option_format(lst->test_values[0]);
    if (!ft_strncmp("NULL", lst->test_values[1], 4))
        value2 = NULL;
    else
        value2 = ft_testfile_option_format(lst->test_values[1]);
    value3 = ft_atoi(ft_testfile_option_format(lst->test_values[2]));
    result = ft_inttester_ssz(libc_func, value1, value2, value3);
    ft_result = ft_inttester_ssz(ft_func, value1, value2, value3);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == SEGFAULT && ft_result == SEGFAULT)
        printf("%s: Segfaults as expected!\n", lst->title);
    if (ft_result != result)
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result == SEGFAULT)
            printf("SEGFAULT\n\tlibcvalue: ");
        else
            printf("%i\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%i\n", result);
    }
}
