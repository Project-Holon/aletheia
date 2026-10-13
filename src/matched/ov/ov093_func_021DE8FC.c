/*
 * unit:     yes
 * function: HAND_ITEM_ThickClub_DoubleAttack, HAND_ITEM_GetChoiceBandHandlers
 * address:  0x021DE8FC
 * packet:   pkt_ov093_021DE8FC
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
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gChoiceBandHandlers     0x021F18D4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gChoiceBandHandlers;

void HAND_ITEM_ThickClub_DoubleAttack(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) - 0x68 <= 1) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 2 << 12);
        }
    }
}

int *HAND_ITEM_GetChoiceBandHandlers(int *p)
{
    *p = 3;
    return &gChoiceBandHandlers;
}
