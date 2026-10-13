/*
 * function: SODATEYA_PutDittoSecond
 * address:  0x021C3A44
 * packet:   pkt_ov021_021C3A44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Applies the special-case hook for species 0x84 holding item 2 (EXACT*: pad).
 *
 * symbols:
 *   SODATEYA_SwapParents  0x021C3A70  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void SODATEYA_SwapParents(u32 *p);

void SODATEYA_PutDittoSecond(void **p)
{
    u32 sp = POKE_TOOL_GetPartyValue(p[0], 5, 0);
    u32 item = POKE_TOOL_GetPartyValue(p[1], 0x6E, 0);

    if (sp == 0x84 && item == 2)
        SODATEYA_SwapParents((u32 *)p);
}
