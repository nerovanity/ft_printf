#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


int main()
{
    int custom_ret, original_ret;

    // Test integer specifier (d, i) with flags
    custom_ret = ft_printf("1. %+d %+d\n", 42, -42);
    original_ret = printf("1. %+d %+d\n", 42, -42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    custom_ret = ft_printf("2. % d % d\n", 42, -42);
    original_ret = printf("2. % d % d\n", 42, -42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    // Test unsigned integer (u)
    custom_ret = ft_printf("3. %u\n", UINT_MAX);
    original_ret = printf("3. %u\n", UINT_MAX);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    // Test string (s) and character (c)
    custom_ret = ft_printf("4. String: %s, Char: %c\n", "Hello, World!", 'A');
    original_ret = printf("4. String: %s, Char: %c\n", "Hello, World!", 'A');
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    // Test hash (#) flag for integers
    custom_ret = ft_printf("5. %#x %#X\n", 255, 255);
    original_ret = printf("5. %#x %#X\n", 255, 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    // Test space and plus together
    custom_ret = ft_printf("6. % +d\n", 123);
    original_ret = printf("6. % +d\n", 123);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    // Edge cases
    custom_ret = ft_printf("7. Empty string: %s\n", "");
    original_ret = printf("7. Empty string: %s\n", "");
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    custom_ret = ft_printf("8. Only %%: %%\n");
    original_ret = printf("8. Only %%: %%\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    custom_ret = ft_printf("9. Negative number: %d\n", -12345);
    original_ret = printf("9. Negative number: %d\n", -12345);
    printf("Return values: ft_printf = %d, printf = %d\n\n", custom_ret, original_ret);

    return 0;
}
