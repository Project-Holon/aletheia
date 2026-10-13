/*
 * file:     unit_021DE3D4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_MachoBraceHalveSpeed, BTL_HANDLER_ITEM_QuickClawMoveFirst, BTL_HANDLER_ITEM_QuickClawShowMessage, BTL_HANDLER_ITEM_GetLaggingTailHandlers
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
 *   gLaggingTailHandlerTable     0x021F1394  data   ov093  a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gQuickClawHandlerTable 0x021F163C data a4
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_HANDLER_ITEM_RollChance  0x021DCFD0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "unit_021DDC44_types.h"

#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Quick Claw and Custap Berry */

extern int BTL_EVENT_GetVar(int varId);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
extern int BTL_HANDLER_ITEM_RollChance(struct BtlSvFlow *flow, unsigned int percent);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
void BTL_HANDLER_ITEM_MachoBraceHalveSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *BTL_HANDLER_ITEM_GetQuickClawHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_QuickClawMoveFirst(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_QuickClawShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern u8 gQuickClawHandlerTable[];

/*
 * Macho Brace, speed event: halves the speed ratio. The original reuses the
 * poke id variable key (2) as the shift count, so the ratio is 2 << 10.
 */
void BTL_HANDLER_ITEM_MachoBraceHalveSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { int pokeIdVar=BTL_EVAR_POKE_ID; if(pokeId == BTL_EVENT_GetVar(pokeIdVar)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, pokeIdVar<<10); }

/* Handler table getter of Quick Claw. */
void *BTL_HANDLER_ITEM_GetQuickClawHandlers(int *handlerCount) { *handlerCount=2; return gQuickClawHandlerTable; }


/* Quick Claw, action order event: with the item percent chance the holder moves first. */
void BTL_HANDLER_ITEM_QuickClawMoveFirst(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 percent;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        percent = BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (BTL_HANDLER_ITEM_RollChance(flow, percent) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0)
            BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
    }
}


/* Quick Claw, use event: shows the message and clears the work word. */
void BTL_HANDLER_ITEM_QuickClawShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, record);
        *work = 0;
    }
}


extern int gLaggingTailHandlerTable[];
int *BTL_HANDLER_ITEM_GetLaggingTailHandlers(int *handlerCount);

/* Handler table getter of Lagging Tail. */
int *BTL_HANDLER_ITEM_GetLaggingTailHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLaggingTailHandlerTable;
}
