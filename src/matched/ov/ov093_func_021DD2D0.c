/*
 * function: HAND_ITEM_LeppaBerryClaimTrigger
 * address: 0x021DD2D0
 * packet: pkt_ov093_021DD2D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_ITEM_FindLastMoveEmptySlot 0x021DD338 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern u8 HAND_ITEM_FindLastMoveEmptySlot(void *, int);
extern int BTL_EVENT_OverwriteVar(int, u32);
void HAND_ITEM_LeppaBerryClaimTrigger(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && HAND_ITEM_FindLastMoveEmptySlot(b, c) != 4)
        BTL_EVENT_OverwriteVar(0x51, 1);
}
