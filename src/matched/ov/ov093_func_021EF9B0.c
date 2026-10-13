/*
 * function: BTL_FIELD_GetCountdownCountIfSet
 * address:  0x021EF9B0
 * packet:   pkt_ov093_021EF9B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

typedef unsigned int u32;

int BTL_FIELD_GetCountdownCountIfSet(u32 *p)
{
    if (p[0] != 0)
        return p[1];
    return 0;
}
