/*
 * function: MANUAL_COMMON_GetGroupValue2
 * address:  0x021B9C40
 * packet:   pkt_021B9C40
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MANUAL_COMMON_GetEntry  0x021B9CFC  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int MANUAL_COMMON_GetEntry(char *, int);

u16 MANUAL_COMMON_GetGroupValue2(char *p, int idx, int c)
{
    return ((u16 *)MANUAL_COMMON_GetEntry(p, idx))[c + 3];
}
