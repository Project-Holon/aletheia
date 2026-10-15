/*
 * function: MANUAL_COMMON_GetCursorIndex
 * address:  0x021BB034
 * packet:   pkt_021BB034
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

u16 MANUAL_COMMON_GetCursorIndex(u16 **p)
{
    u16 *q = *p;
    return (u16)(q[7] - q[6] + 1);
}
