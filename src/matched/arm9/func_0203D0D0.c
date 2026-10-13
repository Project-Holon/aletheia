/*
 * unit:     no
 * function: GFL_NET_IRC_WIRELESS_Exit
 * address:  0x0203D0D0
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IRC_WIRELESS_Destroy  0x0203D9EC  arm
 */

extern void GFL_NET_IRC_WIRELESS_Destroy(void);
void GFL_NET_IRC_WIRELESS_Exit(void){ GFL_NET_IRC_WIRELESS_Destroy(); }
