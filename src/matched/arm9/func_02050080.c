/*
 * function: BILLBOARD_ACT_GetBoard
 * address:  0x02050080
 * packet:   pkt_02050080
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 */

typedef unsigned int u32;

u32 BILLBOARD_ACT_GetBoard(u32 *p)
{
    return p[1];
}
