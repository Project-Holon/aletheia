/*
 * function: MAILTOOL_StoreMailToPartyMon
 * address:  0x021C3E04
 * packet:   pkt_ov136_021C3E04
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb
 *   MAILTOOL_IsMailSent 0x021C3E00 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 */
typedef unsigned int u32;
extern u32 MAILTOOL_IsMailSent(u32 *p);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
int MAILTOOL_StoreMailToPartyMon(u32 *p, void *q)
{
    if (MAILTOOL_IsMailSent(p) == 0) return 0;
    POKE_TOOL_SetPartyValue(q, 0xa7, p[5]);
    return 1;
}
