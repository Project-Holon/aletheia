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

/* Parameter ids of the get/set party-value accessors. */
#define MON_PARAM_BALL 0x98
#define MON_PARAM_HP 0xa0
#define MON_PARAM_MAX_HP 0xa1
#define BALL_HEAL 14

struct PokemonParam;
extern u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *mon);
extern u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *mon, u32 prevState);
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *mon, u32 paramId, u32 unused);
extern void POKE_TOOL_SetPartyValue(struct PokemonParam *mon, u32 paramId, u32 value);
extern void POKE_TOOL_SetStatusCondition(struct PokemonParam *mon, u32 status);

/* A Pokemon caught in a Heal Ball is healed: full HP and no status. */
void EVENT_BATTLE_RETURN_ApplyHealBall(struct PokemonParam *mon)
{
    u32 prevState;
    prevState = POKE_TOOL_DecodePartyParam(mon);
    if (POKE_TOOL_GetPartyValue(mon, MON_PARAM_BALL, 0) == BALL_HEAL) {
        POKE_TOOL_SetPartyValue(mon, MON_PARAM_HP, POKE_TOOL_GetPartyValue(mon, MON_PARAM_MAX_HP, 0));
        POKE_TOOL_SetStatusCondition(mon, 0);
    }
    POKE_TOOL_EncodePartyParam(mon, prevState);
}
