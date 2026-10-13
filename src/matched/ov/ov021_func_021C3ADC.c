/*
 * function: SODATEYA_RollVolbeatSpecies
 * address:  0x021C3ADC
 * packet:   pkt_ov021_021C3ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 *
 * symbols:
 *   SODATEYA_GetSpeciesParent  0x021C3BB0  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern int SODATEYA_GetSpeciesParent(u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);

void SODATEYA_RollVolbeatSpecies(void *a, u32 *out)
{
    u32 sp = POKE_TOOL_GetPartyValue((void *)SODATEYA_GetSpeciesParent((u32)a), 5, 0);

    if (sp == 0x139 || sp == 0x13A) {
        if (func_02005728(2) == 0)
            *out = 0x139;
        else
            *out = 0x13A;
    }
}
