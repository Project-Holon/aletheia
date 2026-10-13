/*
 * file:     unit_021DE0DC.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_JabocaBerryRememberPhysicalAttacker, BTL_HANDLER_ITEM_GetRowapBerryHandlers, BTL_HANDLER_ITEM_RowapBerryRememberSpecialAttacker, BTL_HANDLER_ITEM_RememberAttackerOfCategory
 * address:  0x021DE0DC
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gRowapBerryHandlerTable     0x021F162C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int func_0689C8CC(u16 moveId);
extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
void BTL_HANDLER_ITEM_JabocaBerryRememberPhysicalAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetRowapBerryHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_RowapBerryRememberSpecialAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_RememberAttackerOfCategory(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, int moveCategory);
extern int gRowapBerryHandlerTable[];

/* Jaboca Berry, hit event: remembers the attacker of a physical hit. */
void BTL_HANDLER_ITEM_JabocaBerryRememberPhysicalAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { BTL_HANDLER_ITEM_RememberAttackerOfCategory(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_PHYSICAL); }


/* Handler table getter of Rowap Berry. */
int *BTL_HANDLER_ITEM_GetRowapBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRowapBerryHandlerTable;
}


/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl BTL_HANDLER_ITEM_RememberAttackerOfCategory; add sp, #4; pop {r3, r4, pc}.
 */
/* Rowap Berry, hit event: remembers the attacker of a special hit. */
void BTL_HANDLER_ITEM_RowapBerryRememberSpecialAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { BTL_HANDLER_ITEM_RememberAttackerOfCategory(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_SPECIAL); }


/*
 * Jaboca and Rowap Berry: when the holder is hit by a move of the berry's
 * category (not through a substitute), store the attacker id plus one in the
 * work word and queue a "keep the item" use record. The hit-back damage is
 * dealt later by the use event.
 */
void BTL_HANDLER_ITEM_RememberAttackerOfCategory(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, int moveCategory)
{
    HandExUseItem *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0
        && func_0689C8CC(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0 && moveCategory == BTL_EVENT_GetVar(BTL_EVAR_MOVE_CATEGORY)) {
        BTL_EVENT_KeepFactorRunning(factor);
        *work = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) + 1;
        record = func_021C88A4(flow, HANDEX_KIND_USE_ITEM, pokeId);
        record->useFlags |= HANDEX_USE_ITEM_KEEP_ITEM;
        func_021C88C8(flow, record);
    }
}
