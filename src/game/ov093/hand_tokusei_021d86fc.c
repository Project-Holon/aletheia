/*
 * file:     hand_tokusei_021d86fc.c
 * unit:     yes
 * function: HAND_TOKUSEI_ThickFatHalveFireIce, HAND_TOKUSEI_HugePowerDoubleAttack, HAND_TOKUSEI_SwiftSwimDoubleSpeed, HAND_TOKUSEI_ChlorophyllDoubleSpeed
 * address:  0x021D86FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gHugePowerHandlers 0x021F07C8 data ov093 a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   gSwiftSwimHandlers 0x021F0740 data ov093 a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   gChlorophyllHandlers 0x021F05D8 data a4
 */
#include "btl_action_word_types.h"

void HAND_TOKUSEI_ThickFatHalveFireIce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *HAND_TOKUSEI_GetHugePowerHandlers(u32 *packedInfo);
void HAND_TOKUSEI_HugePowerDoubleAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_SwiftSwimDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *HAND_TOKUSEI_GetSwiftSwimHandlers(u32 *packedInfo);
void HAND_TOKUSEI_ChlorophyllDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *HAND_TOKUSEI_GetChlorophyllHandlers(u32 *packedInfo);
extern u8 gHugePowerHandlers[];
extern u8 gSwiftSwimHandlers[];
extern u8 gChlorophyllHandlers[];

/* Thick Fat: halves the attack power of fire and ice moves against the owner. */
void HAND_TOKUSEI_ThickFatHalveFireIce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_ICE || moveType == POKETYPE_FIRE)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Huge Power and Pure Power: handler table. */
u8 *HAND_TOKUSEI_GetHugePowerHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gHugePowerHandlers;
}

/* Huge Power and Pure Power: doubles the attack power of physical moves. */
void HAND_TOKUSEI_HugePowerDoubleAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: doubles the speed in rain. */
void HAND_TOKUSEI_SwiftSwimDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_RAIN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: handler table. */
u8 *HAND_TOKUSEI_GetSwiftSwimHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gSwiftSwimHandlers;
}

/* Chlorophyll: doubles the speed in sun. */
void HAND_TOKUSEI_ChlorophyllDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Chlorophyll: handler table. */
u8 *HAND_TOKUSEI_GetChlorophyllHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gChlorophyllHandlers;
}
