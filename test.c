#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int main(void) {
    int ret_ft, ret_std;
	int x = 42; // Variables to store return values

    // 1. Basic Tests
    ret_ft = ft_printf("ft_printf: Hello, World!\n");
    ret_std = printf("printf:    Hello, World!\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 2. Character Tests
    ret_ft = ft_printf("ft_printf: Character: %c\n", 'A');
    ret_std = printf("printf:    Character: %c\n", 'A');
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Null Character: %c\n", '\0');
    ret_std = printf("printf:    Null Character: %c\n", '\0');
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 3. String Tests
    ret_ft = ft_printf("ft_printf: String: %s\n", "ft_printf");
    ret_std = printf("printf:    String: %s\n", "ft_printf");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Null String: %s\n", NULL);
    ret_std = printf("printf:    Null String: %s\n", NULL);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 4. Decimal Tests
    ret_ft = ft_printf("ft_printf: Decimal: %d\n", 123);
    ret_std = printf("printf:    Decimal: %d\n", 123);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Negative Decimal: %d\n", -123);
    ret_std = printf("printf:    Negative Decimal: %d\n", -123);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Max Int: %d\n", INT_MAX);
    ret_std = printf("printf:    Max Int: %d\n", INT_MAX);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Min Int: %d\n", INT_MIN);
    ret_std = printf("printf:    Min Int: %d\n", INT_MIN);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 5. Unsigned Tests
    ret_ft = ft_printf("ft_printf: Unsigned: %u\n", 12345);
    ret_std = printf("printf:    Unsigned: %u\n", 12345);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Max Unsigned: %u\n", UINT_MAX);
    ret_std = printf("printf:    Max Unsigned: %u\n", UINT_MAX);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 6. Hexadecimal Tests
    ret_ft = ft_printf("ft_printf: Hexadecimal (lower): %x\n", 255);
    ret_std = printf("printf:    Hexadecimal (lower): %x\n", 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Hexadecimal (upper): %X\n", 255);
    ret_std = printf("printf:    Hexadecimal (upper): %X\n", 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Hex with zero: %x\n", 0);
    ret_std = printf("printf:    Hex with zero: %x\n", 0);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 7. Pointer Tests
    ret_ft = ft_printf("ft_printf: Pointer: %p\n", &x);
    ret_std = printf("printf:    Pointer: %p\n", &x);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Null Pointer: %p\n", NULL);
    ret_std = printf("printf:    Null Pointer: %p\n", NULL);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 8. Mixed Format Tests
    ret_ft = ft_printf("ft_printf: Char: %c, String: %s, Decimal: %d\n", 'A', "Hello", 42);
    ret_std = printf("printf:    Char: %c, String: %s, Decimal: %d\n", 'A', "Hello", 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Unsigned: %u, Hex: %x, Pointer: %p\n", 12345, 255, &x);
    ret_std = printf("printf:    Unsigned: %u, Hex: %x, Pointer: %p\n", 12345, 255, &x);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 9. Edge Case for Consecutive Percent Signs (%%)
    ret_ft = ft_printf("ft_printf: Double Percent: %%\n");
    ret_std = printf("printf:    Double Percent: %%\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Percent Before Specifier: %%s\n");
    ret_std = printf("printf:    Percent Before Specifier: %%s\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("ft_printf: Percent After Specifier: %s%%\n", "Hello");
    ret_std = printf("printf:    Percent After Specifier: %s%%\n", "Hello");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);


    // 11. Stress Test with Long String
    char long_str[5000];
    memset(long_str, 'A', 4999);
    long_str[4999] = '\0';
    ret_ft = ft_printf("Long String: %s\n", long_str);
    ret_std = printf("Long String: %s\n", long_str);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    // 12. Invalid Format Specifier
    ret_ft = ft_printf("Invalid Format: %r\n");
    ret_std = printf("Invalid Format: %r\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret_ft, ret_std);

    return 0;
}
