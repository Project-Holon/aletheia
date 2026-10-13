/*
 * function: HAND_ITEM_LeppaBerryOnLastMoveEmpty
 * address: 0x021DD240
 * packet: pkt_ov093_021DD240
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_ITEM_FindLastMoveEmptySlot 0x021DD338 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern u8 HAND_ITEM_FindLastMoveEmptySlot(void *, int);
extern void HAND_ITEM_PushUseItem(void *, void *, int);
void HAND_ITEM_LeppaBerryOnLastMoveEmpty(void *a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) {
        if (HAND_ITEM_FindLastMoveEmptySlot(b, c) != 4)
            HAND_ITEM_PushUseItem(a, b, c);
    }
}
