/*
 * function: BTL_HANDLER_ITEM_MicleBerryCheckOnSwitchIn
 * address:  0x021DDF98
 * packet:   pkt_ov093_021DDF98
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
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_HANDLER_ITEM_IsHpLowForTrigger  0x021DDE74  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
extern int BTL_HANDLER_ITEM_IsHpLowForTrigger(int a, void *b, int c, unsigned int d);
extern void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c);

void BTL_HANDLER_ITEM_MicleBerryCheckOnSwitchIn(int a, void *b, int c)
{
    u8 j;

    if (c == BTL_EVENT_GetVar(2)) {
        func_021C7CF4(b, c);
        j = BTL_HANDLER_ITEM_GetParam(a, 2);
        if (BTL_HANDLER_ITEM_IsHpLowForTrigger(a, (void *)((int)b), c, j) != 0)
            BTL_HANDLER_ITEM_PushUseItem((void *)a, (void *)((int)b), c);
    }
}
