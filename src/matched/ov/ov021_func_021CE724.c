/*
 * function: COMM_ENTRY_MENU_SetBusyFlags
 * address:  0x021CE724
 * packet:   pkt_ov021_021CE724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a `.word` run in the listing); filed as the witness for
 * the tail-call stub COMM_ENTRY_RecvSessionLock in ov021_func_021CF288.c.
 *
 * symbols:
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void GFL_NET_SetLoginOption(u8 a);

void COMM_ENTRY_MENU_SetBusyFlags(u8 *p)
{
    p[0x576] = 1;
    p[0x577] = 1;
    GFL_NET_SetLoginOption(1);
}
