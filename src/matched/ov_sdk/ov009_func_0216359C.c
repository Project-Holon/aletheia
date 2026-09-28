/*
 * function: char_from_long
 * address:  0x0216359C
 * packet:   pkt_ov009_0216359C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      char_from_long (sha1.o)
 *
 * symbols:
 *   (none)
*/

typedef unsigned long u32;

static void char_from_long(unsigned char *d, unsigned long *s, unsigned int len)
{
    unsigned int i;

    len >>= 2;
    for (i = 0; i < len; i++) {
        u32 v = *s++;
        d[0] = v >> 24;
        d[1] = v >> 16;
        d[2] = v >> 8;
        d[3] = v;
        d += 4;
    }
}
