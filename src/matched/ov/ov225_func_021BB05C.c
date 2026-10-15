/*
 * function: MANUAL_COMMON_GetVisibleCount
 * address:  0x021BB05C
 * packet:   pkt_021BB05C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MANUAL_COMMON_GetLastVisible  0x021BB044  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern u16 MANUAL_COMMON_GetLastVisible(u16 **);

u16 MANUAL_COMMON_GetVisibleCount(u16 **p)
{
    return (u16)(MANUAL_COMMON_GetLastVisible(p) - (*p)[6] + 1);
}
