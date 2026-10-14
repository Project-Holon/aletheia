/*
 * function: POKETRADE_PROC_GetMonSpeciesFlag
 * address: 0x021D95A0
 * packet: pkt_ov119_021D95A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
u32 POKETRADE_PROC_GetMonSpeciesFlag(void *mon)
{
    u32 r = 0;
    if (POKE_TOOL_GetPartyValue(mon, 3, 0) == 1)
        return 1;
    if ((int)POKE_TOOL_GetPartyValue(mon, 5, r) > 0x28b)
        r = 1;
    return r;
}
