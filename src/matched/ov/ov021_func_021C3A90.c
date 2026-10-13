/*
 * function: SODATEYA_SetBaseSpecies
 * address:  0x021C3A90
 * packet:   pkt_ov021_021C3A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the base form of the parent species.
 *
 * symbols:
 *   SODATEYA_GetSpeciesParent  0x021C3BB0  thumb  ov021
 *   SODATEYA_GetBaseSpecies  0x021C4504  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern int SODATEYA_GetSpeciesParent(u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u16 SODATEYA_GetBaseSpecies(u16 sp);

void SODATEYA_SetBaseSpecies(void *a, u32 *out)
{
    *out = SODATEYA_GetBaseSpecies(POKE_TOOL_GetPartyValue((void *)SODATEYA_GetSpeciesParent((u32)a), 5, 0));
}
