/*
 * function: BTL_HANDLER_ITEM_AdamantOrbMovePower
 * address:  0x021DF9C8
 * packet:   pkt_ov093_021DF9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned short u16;
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int BTL_HANDLER_ITEM_GetBoostRatio(int a);

void BTL_HANDLER_ITEM_AdamantOrbMovePower(int self, int a, int b)
{
    u8 v;

    if (b != BTL_EVENT_GetVar(3))
        return;
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4((int *)a, b)) != 0x1e3)
        return;
    v = BTL_EVENT_GetVar(0x16);
    if (v == 0xf || v == 8)
        BTL_EVENT_MultiplyVar(0x31, BTL_HANDLER_ITEM_GetBoostRatio(self));
}
