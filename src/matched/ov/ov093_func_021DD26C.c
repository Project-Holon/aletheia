/*
 * function: BTL_HANDLER_ITEM_LeppaBerryOnAnyMoveEmptyChecked
 * address: 0x021DD26C
 * packet: pkt_ov093_021DD26C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_HANDLER_ITEM_FindEmptyMoveSlot 0x021DD368 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern u8 BTL_HANDLER_ITEM_FindEmptyMoveSlot(void *, int);
extern void BTL_HANDLER_ITEM_PushUseItem(void *, void *, int);
void BTL_HANDLER_ITEM_LeppaBerryOnAnyMoveEmptyChecked(void *a, void *b, int c)
{
    int v;
    if (c == BTL_EVENT_GetVar(2)) {
        v = BTL_EVENT_GetVar(0x2e);
        if (v != 2 && v != 0) return;
        if (BTL_HANDLER_ITEM_FindEmptyMoveSlot(b, c) != 4)
            BTL_HANDLER_ITEM_PushUseItem(a, b, c);
    }
}
