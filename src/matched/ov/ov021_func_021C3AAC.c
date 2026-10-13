/*
 * function: SODATEYA_RollNidoranSpecies
 * address:  0x021C3AAC
 * packet:   pkt_ov021_021C3AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 *
 * symbols:
 *   SODATEYA_GetSpeciesParent  0x021C3BB0  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern int SODATEYA_GetSpeciesParent(u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);

void SODATEYA_RollNidoranSpecies(void *a, u32 *out)
{
    u32 sp = POKE_TOOL_GetPartyValue((void *)SODATEYA_GetSpeciesParent((u32)a), 5, 0);

    if (sp == 0x1D || sp - 0x20 <= 2) {
        if (func_02005728(2) == 0)
            *out = 0x1D;
        else
            *out = 0x20;
    }
}
