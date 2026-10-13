/*
 * function: COMM_ENTRY_MENU_MarkMemberReady
 * address:  0x021CE6F0
 * packet:   pkt_ov021_021CE6F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after COMM_ENTRY_MENU_ProcessStartConfirm; the tail-call stub at 0x021CF31C
 * reaches it through the pool word 0x021CE6F1 with the index narrowed to u8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

void COMM_ENTRY_MENU_MarkMemberReady(u8 *p, u8 i)
{
    p[0x578] |= 1 << i;
}
