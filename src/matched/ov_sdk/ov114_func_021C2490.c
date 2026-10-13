/*
 * function: ghiFreePostAndUpdateConnection
 * address:  0x021C2490
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiRequestToConnection  0x021C0DA4  arm  ov114
 *   ghiFreePost  0x021C2464  arm  ov114
 *   ghiPostCleanupState  0x021C2BB0  arm  ov114
 *
 *
 * Flushes the object selected by `a`, then applies `b`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *ghiRequestToConnection(int);
extern void ghiPostCleanupState(u8 *);
extern void ghiFreePost(u8 *p);

void ghiFreePostAndUpdateConnection(int a, int b)
{
    u8 *p = ghiRequestToConnection(a);
    if (p != 0)
        ghiPostCleanupState(p);
    ghiFreePost((u8 *)b);
}
