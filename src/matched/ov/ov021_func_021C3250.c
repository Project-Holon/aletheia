/*
 * function: SODATEYA_RevertShaymin
 * address:  0x021C3250
 * packet:   pkt_ov021_021C3250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the held item when it is item 0x1EC.
 *
 * symbols:
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

void SODATEYA_RevertShaymin(void *mon)
{
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1EC)
        POKE_TOOL_ChangeForm(mon, 0);
}
