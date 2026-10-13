/*
 * unit:     yes
 * function: HAND_ITEM_ZoomLensRaiseAccuracy, HAND_ITEM_GetLaxIncenseHandlers
 * address:  0x021DE620
 * packet:   pkt_ov093_021DE620
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
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   HAND_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gLaxIncenseHandlers     0x021F1474  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int HAND_ITEM_GetBoostRatio(int a);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gLaxIncenseHandlers;

void HAND_ITEM_ZoomLensRaiseAccuracy(int a, int b, int c)
{
    u8 v;
    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(4);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam((int *)b, v), 1) != 0)
            BTL_EVENT_MultiplyVar(0x35, HAND_ITEM_GetBoostRatio(a));
    }
}

int *HAND_ITEM_GetLaxIncenseHandlers(int *p)
{
    *p = 1;
    return &gLaxIncenseHandlers;
}
