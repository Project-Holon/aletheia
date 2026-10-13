/*
 * file:     unit_021DB9AC.c
 * unit:     yes
 * function: BTL_TOKUSEI_GetMagicGuardHandlers, BTL_TOKUSEI_MagicGuard_ClearEffectFlag, BTL_TOKUSEI_GetStenchHandlers, BTL_TOKUSEI_Stench_SetFlinchChance, BTL_TOKUSEI_GetShadowTagHandlers, BTL_TOKUSEI_ShadowTag_PreventEscape, BTL_TOKUSEI_GetArenaTrapHandlers, BTL_TOKUSEI_ArenaTrap_PreventEscape, BTL_TOKUSEI_GetMagnetPullHandlers
 * address:  0x021DB9AC
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
 *   gMagicGuardHandlers 0x021F06F8 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 *   gShadowTagHandlers 0x021F06E8 data a4
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   gStenchHandlers     0x021F06F0  data   ov093  a4
 *   func_021C8234  0x021C8234  thumb  ov093
 *   gArenaTrapHandlers     0x021F06E0  data   ov093  a4
 *   gMagnetPullHandlers     0x021F06D8  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Magic Guard, Stench, Shadow Tag, Arena Trap, and the table getter of Magnet Pull. */

#define ABILITY_SHADOW_TAG 0x17
#define STENCH_FLINCH_CHANCE 10
#define OPPONENT_ID_BUFFER_SIZE 4

const BtlEventHandler *BTL_TOKUSEI_GetMagicGuardHandlers(int *handlerCount);
void BTL_TOKUSEI_MagicGuard_ClearEffectFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetStenchHandlers(int *handlerCount);
void BTL_TOKUSEI_Stench_SetFlinchChance(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetShadowTagHandlers(int *handlerCount);
void BTL_TOKUSEI_ShadowTag_PreventEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetArenaTrapHandlers(int *handlerCount);
void BTL_TOKUSEI_ArenaTrap_PreventEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetMagnetPullHandlers(int *handlerCount);
extern const BtlEventHandler gMagicGuardHandlers[];
extern const BtlEventHandler gShadowTagHandlers[];
extern const BtlEventHandler gStenchHandlers[];
extern const BtlEventHandler gArenaTrapHandlers[];
extern const BtlEventHandler gMagnetPullHandlers[];

const BtlEventHandler *BTL_TOKUSEI_GetMagicGuardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagicGuardHandlers;
}


/* Magic Guard: when the holder is the target, clear the effect flag. */
void BTL_TOKUSEI_MagicGuard_ClearEffectFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_FLAG, 0);
}


const BtlEventHandler *BTL_TOKUSEI_GetStenchHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gStenchHandlers;
}


/* Stench: when the holder attacks and the move has no flinch chance of its own, give it the Stench chance. */
void BTL_TOKUSEI_Stench_SetFlinchChance(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_FLINCH_BASE_CHANCE) == 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FLINCH_CHANCE, STENCH_FLINCH_CHANCE);
}


const BtlEventHandler *BTL_TOKUSEI_GetShadowTagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gShadowTagHandlers;
}


/* Shadow Tag: opposing pokes cannot escape, unless one of them has Shadow Tag too. */
void BTL_TOKUSEI_ShadowTag_PreventEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (func_021B9A24((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = func_021C7F68(flow, (u16)(func_021C7D00(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (func_021D59B4(func_021C7CF4(flow, opponentIds[i]), BPP_VALUE_CURRENT_ABILITY) == ABILITY_SHADOW_TAG)
                return;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetArenaTrapHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gArenaTrapHandlers;
}


/* Arena Trap: opposing pokes cannot escape while one of them passes the ground check. */
void BTL_TOKUSEI_ArenaTrap_PreventEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (func_021B9A24((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = func_021C7F68(flow, (u16)(func_021C7D00(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (func_021C8234(flow, opponentIds[i]) == 0) {
                BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
                return;
            }
        }
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetMagnetPullHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagnetPullHandlers;
}
