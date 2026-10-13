/*
 * function: HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner
 * address: 0x021D8E58
 * packet: pkt_ov093_021D8E58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_FlowerGiftUpdateForm 0x021D8E1C thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_FlowerGiftUpdateForm(int, void *, int, int *);
void HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner(int a, void *b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(2)) HAND_TOKUSEI_FlowerGiftUpdateForm(a, b, c, d);
}
