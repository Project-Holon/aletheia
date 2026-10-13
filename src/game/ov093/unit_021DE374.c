/*
 * file:     unit_021DE374.c
 * function: func_021DE374, func_021DE3C8
 * address:  0x021DE374
 * packet:   pkt_ov093_021DE374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F156C     0x021F156C  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
#include "unit_021DDC44_types.h"

extern int func_021D775C(int varId);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
extern void func_021D7704(int varId, s32 ratio);

void func_021DE374(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);

/* Bright Powder, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void func_021DE374(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u32 percentLeft;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
        func_021D7704(BTL_EVAR_RATIO, (int)(percentLeft > 0 ? (float)(percentLeft << 12) + 0.5f : (float)(percentLeft << 12) - 0.5f) / 100);
    }
}


extern int d_021F156C[];
int *func_021DE3C8(int *handlerCount);

/* Handler table getter of Macho Brace. */
int *func_021DE3C8(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F156C;
}
