/*
 * function: ghttpSetMaxRecvTime
 * address:  0x021C22EC
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
 *
 *
 * Stores `b` into the +0x188 field of the object selected by `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *ghiRequestToConnection(int);

void ghttpSetMaxRecvTime(int a, int b)
{
    u8 *p = ghiRequestToConnection(a);
    if (p != 0)
        *(u32 *)(p + 0x188) = b;
}
