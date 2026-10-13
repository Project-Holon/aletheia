/*
 * unit:     yes
 * function: BTL_HANDLER_ITEM_MetalPowder_DoubleDefense, BTL_HANDLER_ITEM_GetQuickPowderHandlers
 * address:  0x021DE7E4
 * packet:   pkt_ov093_021DE7E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F14AC     0x021F14AC  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *func_021C7CF4(int *p, int i);
struct QF;
struct R5;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int d_021F14AC;

void BTL_HANDLER_ITEM_MetalPowder_DoubleDefense(int u, int a, int b)
{
    void *m;
    if (b == BTL_EVENT_GetVar(4)) {
        m = func_021C7CF4((int *)a, b);
        if (BTL_POKEPARAM_GetSpecies(m) == 0x84 && BTL_POKEPARAM_IsTransformed(m) == 0) {
            if (BTL_EVENT_GetVar(0x1a) == 1)
                BTL_EVENT_MultiplyVar(0x35, 4 << 11);
        }
    }
}

int *BTL_HANDLER_ITEM_GetQuickPowderHandlers(int *p)
{
    *p = 1;
    return &d_021F14AC;
}
