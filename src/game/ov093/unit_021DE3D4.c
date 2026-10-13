/*
 * file:     unit_021DE3D4.c
 * unit:     yes
 * function: func_021DE3D4, func_021DE3FC, func_021DE440, func_021DE494
 * address:  0x021DE3D4
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
 *   d_021F1394     0x021F1394  data   ov093  a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F163C 0x021F163C data a4
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021DCFD0  0x021DCFD0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "unit_021DDC44_types.h"

#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Quick Claw and Custap Berry */

extern int func_021D775C(int varId);
extern void func_021D7704(int varId, int ratio);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
extern int func_021DCFD0(struct BtlSvFlow *flow, unsigned int percent);
extern int func_021D76BC(int varId, u32 value);
extern void func_021DD044(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
void func_021DE3D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021DE3F0(int *handlerCount);
void func_021DE3FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DE440(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern u8 d_021F163C[];

/*
 * Macho Brace, speed event: halves the speed ratio. The original reuses the
 * poke id variable key (2) as the shift count, so the ratio is 2 << 10.
 */
void func_021DE3D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { int pokeIdVar=BTL_EVAR_POKE_ID; if(pokeId == func_021D775C(pokeIdVar)) func_021D7704(BTL_EVAR_RATIO, pokeIdVar<<10); }

/* Handler table getter of Quick Claw. */
void *func_021DE3F0(int *handlerCount) { *handlerCount=2; return d_021F163C; }


/* Quick Claw, action order event: with the item percent chance the holder moves first. */
void func_021DE3FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 percent;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        percent = func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
        if (func_021DCFD0(flow, percent) != 0 && func_021D76BC(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0)
            func_021DD044(factor, flow, pokeId);
    }
}


/* Quick Claw, use event: shows the message and clears the work word. */
void func_021DE440(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, func_021D70A8(factor));
        func_021C88C8(flow, record);
        *work = 0;
    }
}


extern int d_021F1394[];
int *func_021DE494(int *handlerCount);

/* Handler table getter of Lagging Tail. */
int *func_021DE494(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1394;
}
