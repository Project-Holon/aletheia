/*
 * function: STD_GetStringLength
 * address:  0x0208CC78
 * packet:   pkt_0208CC78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libstd std_string.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Byte
 * steps up to word alignment, then a word-at-a-time zero-byte test, then
 * bytes to the terminator.
 */

typedef unsigned long u32;

int STD_GetStringLength(const char *str)
{
    int n = 0;

    while (((u32)(str + n) & 3) != 0) {
        if (str[n] == '\0')
            return n;
        ++n;
    }
    {
        const u32 *p32 = (const u32 *)(str + n);

        for (;;) {
            u32 y = *p32;

            y = ~(((y & 0x7F7F7F7F) + 0x7F7F7F7F) | y | 0x7F7F7F7F);
            if (y != 0)
                break;
            ++p32;
            n += 4;
        }
    }
    while (str[n] != '\0')
        ++n;
    return n;
}
