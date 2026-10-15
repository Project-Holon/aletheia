/*
 * function: WF2DMAP_MAP_GetHeight
 * address:  0x021C47FC
 * packet:   pkt_ov127_021C47FC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf: ldrh r0,[r0,#2]; bx lr.  Blocker of ov099 func_021BA0F8.
 */

typedef unsigned short u16;

u16 WF2DMAP_MAP_GetHeight(u16 *p)
{
    return p[1];
}
