/*
 * function: add1_be8
 * address:  0x02161748
 * packet:   pkt_ov009_02161748
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      add1_be8 (ssl.o)
 *
 * symbols:
 *   (none)
*/

typedef unsigned char u8;

static void add1_be8(u8 *d)
{
    int i;
    u8 tmp;

    for (i = 8; i != 0; i--) {
        tmp = *--d + 1;
        *d = tmp;
        if (tmp != 0)
            return;
    }
}
