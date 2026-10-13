/*
 * function: ghttpFreePostAndUpdateConnection
 * address:  0x021C2324
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiFreePostAndUpdateConnection  0x021C2490  arm  ov114
 *
 *
 * Null-guarded keyed apply of `b` onto object `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void ghiFreePostAndUpdateConnection(int, int);

void ghttpFreePostAndUpdateConnection(int a, int b)
{
    if (b == 0)
        return;
    ghiFreePostAndUpdateConnection(a, b);
}
