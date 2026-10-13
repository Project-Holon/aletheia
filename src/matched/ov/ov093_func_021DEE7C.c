/*
 * function: BTL_HANDLER_ITEM_PowerHerb_UseItem
 * address:  0x021DEE7C
 * packet:   pkt_ov093_021DEE7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern void BTL_HANDLER_ITEM_PushUseItem(void *, void *, int);
void BTL_HANDLER_ITEM_PowerHerb_UseItem(void *a, void *b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(3) && *d != 0)
        BTL_HANDLER_ITEM_PushUseItem(a, b, c);
}
