/*
 * file:     unit_021DE4A0.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_LaggingTailMoveLast, BTL_HANDLER_ITEM_GetKingsRockHandlers, BTL_HANDLER_ITEM_KingsRockSetFlinchChance, BTL_HANDLER_ITEM_KingsRockFlingFlinch, BTL_HANDLER_ITEM_GetRazorFangHandlers, BTL_HANDLER_ITEM_GetWideLensHandlers, BTL_HANDLER_ITEM_WideLensRaiseAccuracy, BTL_HANDLER_ITEM_RaiseCriticalRankByOne, BTL_HANDLER_ITEM_LuckyPunchRaiseCriticalRankChansey, BTL_HANDLER_ITEM_StickRaiseCriticalRankFarfetchd
 * address:  0x021DE4A0
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
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gKingsRockHandlerTable     0x021F164C  data   ov093  a4
 *   BTL_HANDLER_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gScopeLensHandlerTable 0x021F158C data a4
 *   gLuckyPunchHandlerTable 0x021F146C data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   gStickHandlerTable     0x021F13DC  data   ov093  a4
 *   gZoomLensHandlerTable     0x021F13D4  data   ov093  a4
 *   gRazorFangHandlerTable     0x021F165C  data   ov093  a4
 *   gWideLensHandlerTable     0x021F1584  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

#define KINGS_ROCK_FLINCH_PERCENT 100   /* Fling flinch chance */
#define CRITICAL_RANK_PLUS_ONE 1
#define CRITICAL_RANK_PLUS_TWO 2

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
void BTL_HANDLER_ITEM_LaggingTailMoveLast(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetKingsRockHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_KingsRockSetFlinchChance(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_KingsRockFlingFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetRazorFangHandlers(int *handlerCount);
int *BTL_HANDLER_ITEM_GetWideLensHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_WideLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *BTL_HANDLER_ITEM_GetScopeLensHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_RaiseCriticalRankByOne(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *BTL_HANDLER_ITEM_GetLuckyPunchHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_LuckyPunchRaiseCriticalRankChansey(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetStickHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_StickRaiseCriticalRankFarfetchd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetZoomLensHandlers(int *handlerCount);
/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
extern int gKingsRockHandlerTable[];
extern u8 gScopeLensHandlerTable[];
extern u8 gLuckyPunchHandlerTable[];
extern int gStickHandlerTable;
extern int gZoomLensHandlerTable;
extern int gRazorFangHandlerTable[];
extern int gWideLensHandlerTable[];



/* 021DE4A0  shape F1: gate on BTL_EVENT_GetVar(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021DE4B6; movs r0, #0x11; movs r1, #0; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
/* Lagging Tail, action order event: the holder moves last. */
void BTL_HANDLER_ITEM_LaggingTailMoveLast(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_LAST);
}



/* Handler table getter of King's Rock. */
int *BTL_HANDLER_ITEM_GetKingsRockHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gKingsRockHandlerTable;
}



/* King's Rock, extra effect chance event: sets the flinch chance to the item percent if no chance is fixed yet. */
void BTL_HANDLER_ITEM_KingsRockSetFlinchChance(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { u8 percent; if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_EFFECT_PERCENT_LOCKED)==0) { percent=BTL_HANDLER_ITEM_GetParam(factor,BTL_ITEM_PARAM_VALUE); BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_PERCENT,percent); } }




/* King's Rock, forced use event (Fling): the target flinches for sure. */
void BTL_HANDLER_ITEM_KingsRockFlingFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExFlinch *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_FLINCH, pokeId);
        record->pokeId = pokeId;
        record->percent = KINGS_ROCK_FLINCH_PERCENT;
        func_021C88C8(flow, record);
    }
}


/* Handler table getter of Razor Fang (same handlers as King's Rock). */
int *BTL_HANDLER_ITEM_GetRazorFangHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRazorFangHandlerTable;
}


/* Handler table getter of Wide Lens. */
int *BTL_HANDLER_ITEM_GetWideLensHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWideLensHandlerTable;
}


/* Wide Lens, accuracy event: raises the attacker's accuracy by the item percent. */
void BTL_HANDLER_ITEM_WideLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO,BTL_HANDLER_ITEM_GetBoostRatio(factor)); }


/* Handler table getter of Scope Lens (Razor Claw uses the same table). */
void *BTL_HANDLER_ITEM_GetScopeLensHandlers(int *handlerCount) { *handlerCount=1; return gScopeLensHandlerTable; }


/*
 * lever: u8 local holds getter result before increment; narrow callee argument.
 */
/* Scope Lens and Razor Claw, critical rank event: raises the critical rank by one. */
void BTL_HANDLER_ITEM_RaiseCriticalRankByOne(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { u8 rank; if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) { rank=BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK); BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK,(u8)(rank+CRITICAL_RANK_PLUS_ONE)); } }


/* Handler table getter of Lucky Punch. */
void *BTL_HANDLER_ITEM_GetLuckyPunchHandlers(int *handlerCount) { *handlerCount=1; return gLuckyPunchHandlerTable; }



/* Lucky Punch, critical rank event: raises the critical rank by two when the attacker is a Chansey. */
void BTL_HANDLER_ITEM_LuckyPunchRaiseCriticalRankChansey(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CHANSEY) {
            rank = BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK);
            BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}



/* Handler table getter of Stick. */
int *BTL_HANDLER_ITEM_GetStickHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gStickHandlerTable;
}



/* Stick, critical rank event: raises the critical rank by two when the attacker is a Farfetch'd. */
void BTL_HANDLER_ITEM_StickRaiseCriticalRankFarfetchd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_FARFETCHD) {
            rank = BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_RANK);
            BTL_EVENT_OverwriteVar(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}



/* Handler table getter of Zoom Lens. */
int *BTL_HANDLER_ITEM_GetZoomLensHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gZoomLensHandlerTable;
}
