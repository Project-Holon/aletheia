/*
 * function: POKE_TOOL_AddMoveAlt
 * address:  0x02018238
 * packet:   pkt_02018238
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_AddBoxMoveAlt  0x02018240  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKE_TOOL_AddBoxMoveAlt(void *, u16);

u32 POKE_TOOL_AddMoveAlt(void *p, u16 move)
{
    return POKE_TOOL_AddBoxMoveAlt(p, move);
}
