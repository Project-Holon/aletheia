/*
 * unit:     yes
 * function: HAND_ITEM_MuscleBandBoostPhysical, HAND_ITEM_GetWiseGlassesHandlers
 * address:  0x021DE6CC
 * packet:   pkt_ov093_021DE6CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   HAND_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gWiseGlassesHandlers     0x021F148C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern int WAZA_TOOL_GetDamageType(int a);
extern int HAND_ITEM_GetBoostRatio(int a);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gWiseGlassesHandlers;

void HAND_ITEM_MuscleBandBoostPhysical(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
            BTL_EVENT_MultiplyVar(0x31, HAND_ITEM_GetBoostRatio(a));
    }
}

int *HAND_ITEM_GetWiseGlassesHandlers(int *p)
{
    *p = 1;
    return &gWiseGlassesHandlers;
}
