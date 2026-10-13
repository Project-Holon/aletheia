/*
 * function: EVENT_BATTLE_RETURN_ApplyHealBall
 * address: 0x021B9D04
 * packet: pkt_ov092_021B9D04
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_SetStatusCondition 0x02017F9C thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb  arm9
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb  arm9
 * extent: code ends at 0x021B9D44; remaining handed extent is rodata.
 */
typedef unsigned int u32;
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetStatusCondition(void *p, u32 v);
void EVENT_BATTLE_RETURN_ApplyHealBall(void *p)
{
    u32 saved;
    u32 zero;
    saved = POKE_TOOL_DecodePartyParam(p);
    zero = 0;
    if (POKE_TOOL_GetPartyValue(p, 0x98, 0) == 14) {
        POKE_TOOL_SetPartyValue(p, 0xa0, POKE_TOOL_GetPartyValue(p, 0xa1, zero));
        POKE_TOOL_SetStatusCondition(p, zero);
    }
    POKE_TOOL_EncodePartyParam(p, saved);
}
