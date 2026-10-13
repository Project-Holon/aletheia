/*
 * function: ITEMMENU_MoveSlot
 * address: 0x021B624C
 * packet: pkt_ov070_021B624C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_SwapSlots 0x021B621C thumb ov070
 */
typedef unsigned char  u8;
extern void ITEMMENU_SwapSlots(u8 *p, int a, int b);
void ITEMMENU_MoveSlot(void *p, int a, int b)
{
    if (a == b) return;
    if (a < b) {
        for (; a < b; a++) ITEMMENU_SwapSlots(p, a, a + 1);
    } else {
        for (; a > b; a--) ITEMMENU_SwapSlots(p, a, a - 1);
    }
}
