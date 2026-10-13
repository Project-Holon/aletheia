/*
 * file:     unit_021DE0DC.c
 * unit:     yes
 * function: func_021DE0DC, func_021DE0EC, func_021DE0F8, func_021DE108
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F162C     0x021F162C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

extern int func_021D775C(int varId);
extern int func_0689C8CC(u16 moveId);
extern void func_021D70C8(struct BtlEventFactor *factor);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
void func_021DE0DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DE0EC(int *handlerCount);
void func_021DE0F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE108(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, int moveCategory);
extern int d_021F162C[];

/* Jaboca Berry, hit event: remembers the attacker of a physical hit. */
void func_021DE0DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { func_021DE108(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_PHYSICAL); }


/* Handler table getter of Rowap Berry. */
int *func_021DE0EC(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F162C;
}


/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021DE108; add sp, #4; pop {r3, r4, pc}.
 */
/* Rowap Berry, hit event: remembers the attacker of a special hit. */
void func_021DE0F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { func_021DE108(factor, flow, pokeId, work, BTL_MOVE_CATEGORY_SPECIAL); }


/*
 * Jaboca and Rowap Berry: when the holder is hit by a move of the berry's
 * category (not through a substitute), store the attacker id plus one in the
 * work word and queue a "keep the item" use record. The hit-back damage is
 * dealt later by the use event.
 */
void func_021DE108(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, int moveCategory)
{
    HandExUseItem *record;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_HIT_SUBSTITUTE) == 0
        && func_0689C8CC(func_021D775C(BTL_EVAR_MOVE_ID)) == 0 && moveCategory == func_021D775C(BTL_EVAR_MOVE_CATEGORY)) {
        func_021D70C8(factor);
        *work = func_021D775C(BTL_EVAR_ATTACKER_ID) + 1;
        record = func_021C88A4(flow, HANDEX_KIND_USE_ITEM, pokeId);
        record->useFlags |= HANDEX_USE_ITEM_KEEP_ITEM;
        func_021C88C8(flow, record);
    }
}
