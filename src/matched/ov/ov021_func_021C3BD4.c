/*
 * function: SODATEYA_InheritFormShellos
 * address:  0x021C3BD4
 * packet:   pkt_ov021_021C3BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the parent's form for species 0x1A6..0x1A7.
 *
 * symbols:
 *   SODATEYA_GetFormParent  0x021C3C5C  thumb  ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern int SODATEYA_GetFormParent(u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

void SODATEYA_InheritFormShellos(void *a, u32 *out)
{
    void *mon = (void *)SODATEYA_GetFormParent((u32)a);
    u32 sp = POKE_TOOL_GetPartyValue(mon, 5, 0);

    if (sp - 0x1A6 <= 1)
        out[1] = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
}
