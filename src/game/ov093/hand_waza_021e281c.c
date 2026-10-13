/*
 * file:     hand_waza_021e281c.c
 * unit:     yes
 * function: HAND_WAZA_RevengeDoublePowerOnHit, HAND_WAZA_FlailCalcPower, HAND_WAZA_FacadeDoublePowerOnStatus
 * address:  0x021E281C
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
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gFlailHandlers     0x021F26AC  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gFlailPowerTable     0x021F2CA8  data   ov093  a2
 *   d_021F2CAA     0x021F2CAA  data   ov093  a2
 *   gFacadeHandlers     0x021F249C  data   ov093  a4
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gPaybackHandlers     0x021F2444  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int BTL_POKEPARAM_GetHitRecord(const struct BtlPokeParam *poke, int turnsAgo, u32 hitsAgo, HandHitRecord *out);
extern void BTLV_CORE_EventScaleDamage(int ratio);
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *poke);

void HAND_WAZA_RevengeDoublePowerOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FlailGetHandlers(int *handlerCount);
void HAND_WAZA_FlailCalcPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FacadeGetHandlers(int *handlerCount);
void HAND_WAZA_FacadeDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PaybackGetHandlers(int *handlerCount);
extern BtlEventHandler gFlailHandlers[]; /* Flail and Reversal handler table */
extern HandFlailRow gFlailPowerTable[];    /* Flail and Reversal power table, five rows */
extern BtlEventHandler gFacadeHandlers[]; /* Facade handler table */
extern BtlEventHandler gPaybackHandlers[]; /* Payback handler table */


/*
 * Revenge and Avalanche, base power event: the power doubles when the target
 * damaged the user earlier this turn.
 */
void HAND_WAZA_RevengeDoublePowerOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u8 targetId;
    u8 hitIndex;
    HandHitRecord hit;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        hitIndex = 0;
        while (BTL_POKEPARAM_GetHitRecord(poke, 0, hitIndex++, &hit) != 0) {
            if (hit.attackerId == targetId && hit.damage != 0) {
                BTLV_CORE_EventScaleDamage(2);
                return;
            }
        }
    }
}


/* Flail and Reversal handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FlailGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFlailHandlers;
}


/* Flail and Reversal, base power event: the lower the HP ratio (in 48ths), the higher the power. */
void HAND_WAZA_FlailCalcPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    int hp;
    int maxHp;
    u32 hpRatio;
    u32 rowIndex;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hp = func_021D59B4(poke, BTL_VALUE_HP);
        maxHp = func_021D59B4(poke, BTL_VALUE_MAX_HP);
        hpRatio = hp * 0x30 / maxHp;
        if (hpRatio == 0)
            hpRatio = 1;
        for (rowIndex = 0; rowIndex < 5; rowIndex++) {
            if (hpRatio <= gFlailPowerTable[rowIndex].maxRatio)
                break;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, gFlailPowerTable[rowIndex].power);
    }
}


/* Facade handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FacadeGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFacadeHandlers;
}


/* Facade, power ratio event: the power doubles when the user is burned, poisoned or paralyzed. */
void HAND_WAZA_FacadeDoublePowerOnStatus(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int majorStatus;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        majorStatus = BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (majorStatus == BTL_MAJOR_STATUS_POISON || majorStatus == BTL_MAJOR_STATUS_PARALYSIS || majorStatus == BTL_MAJOR_STATUS_BURN)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_2_0);
    }
}


/* Payback handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_PaybackGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPaybackHandlers;
}
