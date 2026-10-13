/*
 * function: BTL_HANDLER_ITEM_CureSickOnTrigger
 * address:  0x021DD158
 * packet:   pkt_ov093_021DD158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_TryGetVar  0x021D778C  thumb  ov093
 *   BTL_HANDLER_ITEM_CheckHasSick  0x021DD1D8  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_TryGetVar(int key, int *out);
extern int BTL_HANDLER_ITEM_CheckHasSick(u8 *b, int c, int d);
extern void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c);

void BTL_HANDLER_ITEM_CureSickOnTrigger(u8 *a, u8 *b, int c, int d)
{
    int loc;
    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_TryGetVar(0x2e, &loc) == 0 || loc == 3 || loc == 0) {
            if (BTL_HANDLER_ITEM_CheckHasSick(b, c, d) != 0)
                BTL_HANDLER_ITEM_PushUseItem(a, b, c);
        }
    }
}
