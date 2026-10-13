/*
 * function: PMS_SELECT_GRAPHIC_ReadPointer
 * address:  0x021C1848
 * packet:   pkt_ov110_021C1848
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * First-word accessor.
 */

typedef unsigned int u32;

u32 PMS_SELECT_GRAPHIC_ReadPointer(u32 *p)
{
    return *p;
}
