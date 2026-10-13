/*
 * function: FISHING_HideBiteMark
 * address:  0x021C6018
 * packet:   pkt_ov021_021C6018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 */

typedef unsigned int u32;
extern void FIELD_EFFECT_DeleteObject(u32 a);
void FISHING_HideBiteMark(u32 *p)
{
    if (p[11] != 0) {
        FIELD_EFFECT_DeleteObject(p[11]);
        p[11] = 0;
    }
}
