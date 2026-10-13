/*
 * file:     unit_021DE620.c
 * unit:     yes
 * function: func_021DE620, func_021DE668
 * address:  0x021DE620
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1474     0x021F1474  data   ov093  a4
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F13E4     0x021F13E4  data   a4
 */
#include "unit_021DDC44_types.h"

#define TURN_FLAG_ACTED 1   /* the Pokemon has acted this turn */

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int func_021D5BB0(struct BtlPokeParam *poke, u32 flag);
extern int func_021DD008(struct BtlEventFactor *factor);
extern void func_021D7704(int varId, int ratio);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
void func_021DE620(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE65C(int *handlerCount);
void func_021DE668(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE6C0(int *handlerCount);
extern int d_021F1474;
extern int d_021F13E4;


/* Zoom Lens, accuracy event: raises the accuracy by the item percent when the defender has already acted. */
void func_021DE620(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 defenderId;
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        defenderId = func_021D775C(BTL_EVAR_DEFENDER_ID);
        if (func_021D5BB0(func_021C7CF4(flow, defenderId), TURN_FLAG_ACTED) != 0)
            func_021D7704(BTL_EVAR_RATIO, func_021DD008(factor));
    }
}


/* Handler table getter of Lax Incense. */
int *func_021DE65C(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F1474;
}


/* Lax Incense, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void func_021DE668(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 percentLeft;
    float ratio;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
        if (percentLeft != 0)
            ratio = 0.5f + (float)(percentLeft << 12);
        else
            ratio = (float)(percentLeft << 12) - 0.5f;
        func_021D7704(BTL_EVAR_RATIO, (int)ratio / 100);
    }
}


/* Handler table getter of Muscle Band. */
int *func_021DE6C0(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F13E4;
}
