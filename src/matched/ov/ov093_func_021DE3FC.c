/*
 * function: BTL_HANDLER_ITEM_QuickClawMoveFirst
 * address:  0x021DE3FC
 * packet:   pkt_ov093_021DE3FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_HANDLER_ITEM_RollChance  0x021DCFD0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
extern int BTL_HANDLER_ITEM_RollChance(int *a, unsigned int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c);

void BTL_HANDLER_ITEM_QuickClawMoveFirst(int a, void *b, int c)
{
    u8 j;

    if (c == BTL_EVENT_GetVar(2)) {
        j = BTL_HANDLER_ITEM_GetParam(a, 2);
        if (BTL_HANDLER_ITEM_RollChance(b, j) != 0 && BTL_EVENT_OverwriteVar(0x11, 2) != 0)
            BTL_HANDLER_ITEM_PushUseItem((void *)a, b, c);
    }
}
