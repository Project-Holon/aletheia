/*
 * function: MANUAL_COMMON_GetLastVisible
 * address:  0x021BB044
 * packet:   pkt_021BB044
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

u16 MANUAL_COMMON_GetLastVisible(u16 **p)
{
    u16 *q = *p;
    u16 a = (u16)(q[6] + 5);
    u16 b = q[2];
    if (a < b)
        return a;
    return (u16)(b - 1);
}
