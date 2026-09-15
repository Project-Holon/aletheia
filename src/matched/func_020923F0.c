/*
 * function: func_020923F0
 * address:  0x020923F0
 * packet:   pkt_02092120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-wise memcmp implementation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020923F0.c \
 *       --func func_020923F0 --addr 0x020923F0 --arm
 */

typedef unsigned int size_t;

int func_020923F0(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    if (n != 0) {
        do {
            if (*p1++ != *p2++) {
                return (p1[-1] < p2[-1]) ? -1 : 1;
            }
        } while (--n != 0);
    }

    return 0;
}
