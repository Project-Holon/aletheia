/*
 * function: SODATEYA_ApplyPhioneRule
 * address:  0x021C3B0C
 * packet:   pkt_ov021_021C3B0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Manaphy parents produce Phione.
 *
 * symbols:
 *   SODATEYA_GetSpeciesParent  0x021C3BB0  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern int SODATEYA_GetSpeciesParent(u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

void SODATEYA_ApplyPhioneRule(void *a, u32 *out)
{
    if (POKE_TOOL_GetPartyValue((void *)SODATEYA_GetSpeciesParent((u32)a), 5, 0) == 0x1EA)
        *out = 0x1E9;
}
