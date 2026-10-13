/*
 * function: HAND_ITEM_LeppaBerryOnEaten
 * address: 0x021DD2F8
 * packet: pkt_ov093_021DD2F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_ITEM_PushRecoverPp 0x021DD39C thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int HAND_ITEM_PushRecoverPp(int, void *, int, int, int);
void HAND_ITEM_LeppaBerryOnEaten(int a, void *b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(2)) HAND_ITEM_PushRecoverPp(a, b, c, (int)d, 0);
}
