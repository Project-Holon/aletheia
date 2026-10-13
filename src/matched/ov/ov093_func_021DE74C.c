/*
 * unit:     yes
 * function: BTL_HANDLER_ITEM_DeepSeaToothDoubleSpAtk, BTL_HANDLER_ITEM_GetDeepSeaScaleHandlers
 * address:  0x021DE74C
 * packet:   pkt_ov093_021DE74C
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
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gDeepSeaScaleHandlerTable     0x021F139C  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *func_021C7CF4(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gDeepSeaScaleHandlerTable;

void BTL_HANDLER_ITEM_DeepSeaToothDoubleSpAtk(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4((int *)a, b)) == 0x16e) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
                BTL_EVENT_MultiplyVar(0x35, 2 << 12);
        }
    }
}

int *BTL_HANDLER_ITEM_GetDeepSeaScaleHandlers(int *p)
{
    *p = 1;
    return &gDeepSeaScaleHandlerTable;
}
