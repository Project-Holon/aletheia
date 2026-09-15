/*
 * function: func_020923C4
 * address:  0x020923C4
 * packet:   pkt_02092120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-wise memchr implementation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020923C4.c \
 *       --func func_020923C4 --addr 0x020923C4 --arm
 */

typedef unsigned int size_t;

void *func_020923C4(const void *s, int c, size_t n)
{
    const unsigned char *p = (const unsigned char *)s;
    unsigned char uc = (unsigned char)c;

    if (n != 0) {
        do {
            if (*p++ == uc) {
                return (void *)(p - 1);
            }
        } while (--n != 0);
    }

    return (void *)0;
}
