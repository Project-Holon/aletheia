/*
 * function: BTL_HANDLER_ITEM_HpBerryCheckAndUse
 * address:  0x021DDE30
 * packet:   pkt_ov093_021DDE30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_IsHpLowForTrigger  0x021DDE74  thumb  ov093
 *   BTL_HANDLER_ITEM_IsHpAtOrBelowFraction  0x021DDEA4  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_HANDLER_ITEM_IsHpLowForTrigger(int a, void *b, int c, unsigned int d);
extern int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(void *a, int b, u32 n);
extern void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c);

void BTL_HANDLER_ITEM_HpBerryCheckAndUse(int a, int b, int c, int d, int e)
{
    int r;

    if (c == BTL_EVENT_GetVar(2)) {
        if (e != 0)
            r = BTL_HANDLER_ITEM_IsHpLowForTrigger(a, (void *)b, c, d);
        else
            r = BTL_HANDLER_ITEM_IsHpAtOrBelowFraction((void *)b, c, d);
        if (r != 0)
            BTL_HANDLER_ITEM_PushUseItem((void *)a, (void *)b, c);
    }
}
