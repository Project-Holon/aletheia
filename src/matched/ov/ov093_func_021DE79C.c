/*
 * unit:     yes
 * function: HAND_ITEM_DeepSeaScaleDoubleSpDef, HAND_ITEM_GetMetalPowderHandlers
 * address:  0x021DE79C
 * packet:   pkt_ov093_021DE79C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gMetalPowderHandlers     0x021F1454  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gMetalPowderHandlers;

void HAND_ITEM_DeepSeaScaleDoubleSpDef(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) == 0x16e) {
            if (BTL_EVENT_GetVar(0x1a) == 2)
                BTL_EVENT_MultiplyVar(0x35, 4 << 11);
        }
    }
}

int *HAND_ITEM_GetMetalPowderHandlers(int *p)
{
    *p = 1;
    return &gMetalPowderHandlers;
}
