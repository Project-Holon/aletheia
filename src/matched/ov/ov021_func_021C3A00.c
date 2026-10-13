/*
 * function: SODATEYA_SortParentsByGender
 * address:  0x021C3A00
 * packet:   pkt_ov021_021C3A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SODATEYA_SwapParents  0x021C3A70  thumb  ov021
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern void SODATEYA_SwapParents(u32 *p);

void SODATEYA_SortParentsByGender(u32 *p)
{
    u32 a = POKE_TOOL_GetPartyValue((void *)p[0], 0x6e, 0);

    POKE_TOOL_GetPartyValue((void *)p[1], 0x6e, 0);
    if (a == 1)
        SODATEYA_SwapParents(p);
    POKE_TOOL_GetPartyValue((void *)p[0], 0x6e, 0);
    if (POKE_TOOL_GetPartyValue((void *)p[1], 0x6e, 0) == 0)
        SODATEYA_SwapParents(p);
}
