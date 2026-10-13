/*
 * function: func_021B9D04
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
extern u32 func_02017E1C(struct PokemonParam *mon, u32 paramId, u32 unused);
extern void func_02017E40(struct PokemonParam *mon, u32 paramId, u32 value);
extern void POKE_TOOL_SetStatusCondition(struct PokemonParam *mon, u32 status);

/* A Pokemon caught in a Heal Ball is healed: full HP and no status. */
void func_021B9D04(struct PokemonParam *mon)
{
    u32 prevState;
    prevState = POKE_TOOL_DecodePartyParam(mon);
    if (func_02017E1C(mon, MON_PARAM_BALL, 0) == BALL_HEAL) {
        func_02017E40(mon, MON_PARAM_HP, func_02017E1C(mon, MON_PARAM_MAX_HP, 0));
        POKE_TOOL_SetStatusCondition(mon, 0);
    }
    POKE_TOOL_EncodePartyParam(mon, prevState);
}
