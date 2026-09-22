/*
 * function: func_020929E8
 * address:  0x020929E8
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     MSL printf.c `long2str`: the 32-bit integer conversion of the
 *           printf back end, written as the MSL source has it.  The format
 *           descriptor is MSL's 16-byte `print_format` passed BY VALUE
 *           (six u8 option bytes, then int field_width at +8 and int
 *           precision at +0xC), which is what the home-area push and the
 *           [sp,#0x40..0x4c] reads are.  The dead 64-bit INT_MIN guard in
 *           the image (`asr r0,sl,#31; cmp r0,#0x80000000; cmpeq sl,#0`) is
 *           the source comparing the 32-bit `num` against the 64-bit
 *           constant 0x8000000000000000 (LLONG_MIN), promoted.  The digit
 *           pointer is `unsigned char *` (the `*p != '0'` test is ldrb).
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */
typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

unsigned char *func_020929E8(long num, unsigned char *buff, print_format format)
{
    unsigned long unsigned_num, base;
    unsigned char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            if (num != 0x8000000000000000LL)
                unsigned_num = -num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format.sign_options = 0;
        break;
    case 'u':
        base = 10;
        format.sign_options = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format.sign_options = 0;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == 2) {
        format.precision = format.field_width;
        if (minus || format.sign_options)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > 509)
        return 0;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}
