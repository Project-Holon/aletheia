/*
 * file:     hand_waza_021e396c.c
 * unit:     yes
 * function: HAND_WAZA_MagnitudeSetDefaultLevel, HAND_WAZA_GetSurfHandlers, HAND_WAZA_SurfHitDiving, HAND_WAZA_SurfDoubleDamageVsDiving, HAND_WAZA_StompDoubleDamageVsMinimized
 * address:  0x021E396C
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gStompHandlers     0x021F2804  data   a4
 *   gFalseSwipeHandlers     0x021F27FC  data   a4
 *   gSurfHandlers     0x021F2AB8  data   ov093  a4
 */
#include "hand_waza_021e396c_types.h"

struct BtlEventFactor;
void HAND_WAZA_MagnitudeSetDefaultLevel(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *magnitudeLevel);
int *HAND_WAZA_GetSurfHandlers(int *handlerCount);
void HAND_WAZA_SurfHitDiving(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_SurfDoubleDamageVsDiving(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetStompHandlers(int *handlerCount);
void HAND_WAZA_StompDoubleDamageVsMinimized(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetFalseSwipeHandlers(int *handlerCount);
extern int gStompHandlers[];
extern int gFalseSwipeHandlers[];
extern int gSurfHandlers[];

/* Magnitude (move 222): event 0x37 of its table, whose other handler is in the previous unit.
   Defaults the magnitude level to 10 when none was chosen and publishes it. */
void HAND_WAZA_MagnitudeSetDefaultLevel(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *magnitudeLevel)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (*magnitudeLevel == 0)
            *magnitudeLevel = 10;
        BTL_EVENT_OverwriteVar(BTL_EVAR_MAGNITUDE, *magnitudeLevel);
    }
}

/* Surf (move 57): handler table, 2 rows. */
int *HAND_WAZA_GetSurfHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gSurfHandlers;
}

/* Surf, event 0x99: the move can hit a target that is diving. */
void HAND_WAZA_SurfHitDiving(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_TARGET_SEMI_INVULNERABLE) == BTL_SEMI_INVULNERABLE_DIVING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_BY_SEMI_INVULNERABLE, 0);
    }
}

/* Surf, event 0x47: doubles the damage against a target that is diving. */
void HAND_WAZA_SurfDoubleDamageVsDiving(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    int contFlag;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        /* 4 << 11 is 2.0 in the ratio format; the flag number is reused for the shift (register reuse of the original). */
        contFlag = BTL_CONT_FLAG_DIVING;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_DIVING) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, contFlag << 11);
    }
}

/* Stomp (move 23) and Steamroller (move 537): handler table, 1 row. */
int *HAND_WAZA_GetStompHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gStompHandlers;
}

/* Stomp and Steamroller, event 0x47: doubles the damage against a minimized target. */
void HAND_WAZA_StompDoubleDamageVsMinimized(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    int contFlag;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        /* 8 << 10 is 2.0 in the ratio format. */
        contFlag = BTL_CONT_FLAG_MINIMIZED;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_MINIMIZED) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, contFlag << 10);
    }
}

/* False Swipe (move 206): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetFalseSwipeHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFalseSwipeHandlers;
}
