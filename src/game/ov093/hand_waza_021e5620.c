/*
 * file:     hand_waza_021e5620.c
 * unit:     yes
 * function: HAND_WAZA_LunarDanceSetPosEffect, HAND_WAZA_HealingWishSetPosEffect
 * address:  0x021E5620
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHealingWishHandlers     0x021F2694  data   ov093  a4
 *   gWishHandlers     0x021F254C  data   ov093  a4
 */
#include "hand_waza_021e5620_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, unsigned int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
void HAND_WAZA_LunarDanceSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetHealingWishHandlers(int *handlerCount);
void HAND_WAZA_HealingWishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetWishHandlers(int *handlerCount);
extern int gHealingWishHandlers[];
extern int gWishHandlers[];


/* Lunar Dance: arm the position effect for the slot and let the user faint. */
void HAND_WAZA_LunarDanceSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_LUNAR_DANCE;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}


/* Healing Wish getter: one handler row. */
int *HAND_WAZA_GetHealingWishHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHealingWishHandlers;
}


/* Healing Wish: arm the position effect for the slot and let the user faint. */
void HAND_WAZA_HealingWishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_HEALING_WISH;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}


/* Wish getter: one handler row. */
int *HAND_WAZA_GetWishHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWishHandlers;
}
