/*
 * file:     unit_021DE4A0.c
 * unit:     yes
 * function: func_021DE4A0, func_021DE4B8, func_021DE4C4, func_021DE4F4, func_021DE520, func_021DE52C, func_021DE538, func_021DE564, func_021DE598, func_021DE5DC
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F164C     0x021F164C  data   ov093  a4
 *   func_021DD008 0x021DD008 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F158C 0x021F158C data a4
 *   d_021F146C 0x021F146C data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   d_021F13DC     0x021F13DC  data   ov093  a4
 *   d_021F13D4     0x021F13D4  data   ov093  a4
 *   d_021F165C     0x021F165C  data   ov093  a4
 *   d_021F1584     0x021F1584  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

#define KINGS_ROCK_FLINCH_PERCENT 100   /* Fling flinch chance */
#define CRITICAL_RANK_PLUS_ONE 1
#define CRITICAL_RANK_PLUS_TWO 2

extern int func_021D775C(int varId);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
extern int func_021D76BC(int varId, u32 value);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int func_021DD008(struct BtlEventFactor *factor);
extern void func_021D7704(int varId, int ratio);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 func_021D5444(struct BtlPokeParam *poke);
void func_021DE4A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE4B8(int *handlerCount);
void func_021DE4C4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DE4F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE520(int *handlerCount);
int *func_021DE52C(int *handlerCount);
void func_021DE538(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021DE558(int *handlerCount);
void func_021DE564(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021DE58C(int *handlerCount);
void func_021DE598(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE5D0(int *handlerCount);
void func_021DE5DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE614(int *handlerCount);
/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
extern int d_021F164C[];
extern u8 d_021F158C[];
extern u8 d_021F146C[];
extern int d_021F13DC;
extern int d_021F13D4;
extern int d_021F165C[];
extern int d_021F1584[];



/* 021DE4A0  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DE4B6; movs r0, #0x11; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
/* Lagging Tail, action order event: the holder moves last. */
void func_021DE4A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D76BC(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_LAST);
}



/* Handler table getter of King's Rock. */
int *func_021DE4B8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F164C;
}



/* King's Rock, extra effect chance event: sets the flinch chance to the item percent if no chance is fixed yet. */
void func_021DE4C4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { u8 percent; if(pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D775C(BTL_EVAR_EFFECT_PERCENT_LOCKED)==0) { percent=func_021DCFF8(factor,BTL_ITEM_PARAM_VALUE); func_021D76BC(BTL_EVAR_EFFECT_PERCENT,percent); } }




/* King's Rock, forced use event (Fling): the target flinches for sure. */
void func_021DE4F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExFlinch *record;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_FLINCH, pokeId);
        record->pokeId = pokeId;
        record->percent = KINGS_ROCK_FLINCH_PERCENT;
        func_021C88C8(flow, record);
    }
}


/* Handler table getter of Razor Fang (same handlers as King's Rock). */
int *func_021DE520(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F165C;
}


/* Handler table getter of Wide Lens. */
int *func_021DE52C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1584;
}


/* Wide Lens, accuracy event: raises the attacker's accuracy by the item percent. */
void func_021DE538(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) func_021D7704(BTL_EVAR_RATIO,func_021DD008(factor)); }


/* Handler table getter of Scope Lens (Razor Claw uses the same table). */
void *func_021DE558(int *handlerCount) { *handlerCount=1; return d_021F158C; }


/*
 * lever: u8 local holds getter result before increment; narrow callee argument.
 */
/* Scope Lens and Razor Claw, critical rank event: raises the critical rank by one. */
void func_021DE564(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { u8 rank; if(pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) { rank=func_021D775C(BTL_EVAR_CRITICAL_RANK); func_021D76BC(BTL_EVAR_CRITICAL_RANK,(u8)(rank+CRITICAL_RANK_PLUS_ONE)); } }


/* Handler table getter of Lucky Punch. */
void *func_021DE58C(int *handlerCount) { *handlerCount=1; return d_021F146C; }



/* Lucky Punch, critical rank event: raises the critical rank by two when the attacker is a Chansey. */
void func_021DE598(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D5444(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CHANSEY) {
            rank = func_021D775C(BTL_EVAR_CRITICAL_RANK);
            func_021D76BC(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}



/* Handler table getter of Stick. */
int *func_021DE5D0(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F13DC;
}



/* Stick, critical rank event: raises the critical rank by two when the attacker is a Farfetch'd. */
void func_021DE5DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 rank;
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D5444(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_FARFETCHD) {
            rank = func_021D775C(BTL_EVAR_CRITICAL_RANK);
            func_021D76BC(BTL_EVAR_CRITICAL_RANK, (u8)(rank + CRITICAL_RANK_PLUS_TWO));
        }
    }
}



/* Handler table getter of Zoom Lens. */
int *func_021DE614(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F13D4;
}
