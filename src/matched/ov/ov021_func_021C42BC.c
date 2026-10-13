/*
 * function: SODATEYA_AddVoltTackle
 * address:  0x021C42BC
 * packet:   pkt_ov021_021C42BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pikachu offspring learns move 0x158 when a parent holds item 0xEC.
 *
 * symbols:
 *   SODATEYA_AddMove  0x021C42F4  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void SODATEYA_AddMove(u32 *q, u32 move);

void SODATEYA_AddVoltTackle(void **p, u32 *q)
{
    if (q[0] == 0xAC) {
        if (POKE_TOOL_GetPartyValue(p[0], 6, 0) == 0xEC || POKE_TOOL_GetPartyValue(p[1], 6, 0) == 0xEC)
            SODATEYA_AddMove(q, 0x158);
    }
}
