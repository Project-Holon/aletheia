/*
 * function: func_0208CCFC
 * address:  0x0208CCFC
 * packet:   pkt_0208CCFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_GetStringNLength (std_string.o)
 */

int func_0208CCFC(const char *str, int len)
{
    int n;
    const unsigned long *p32;
    unsigned long y;

    for (n = 0; ((unsigned long)(str + n) & 3) != 0 && n < len; n++) {
        if (str[n] == '\0') {
            return n;
        }
    }

    p32 = (const unsigned long *)(str + n);
    for (; n < len - 4; n += 4, p32++) {
        y = *p32;
        y = ~(((y & 0x7f7f7f7f) + 0x7f7f7f7f) | y | 0x7f7f7f7f);
        if (y != 0) {
            break;
        }
    }

    while (str[n] != '\0' && n < len) {
        n++;
    }
    return n;
}
