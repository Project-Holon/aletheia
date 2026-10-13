/*
 * function: GFL_NET_IRC_WIRELESS_IsActive
 * address:  0x0203DA4C
 * packet:   pkt_0203DA4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   d_021469F0   0x021469F0  data  a4
 */

typedef unsigned int u32;

extern u32 d_021469F0[];

int GFL_NET_IRC_WIRELESS_IsActive(void)
{
    return d_021469F0[0] != 0;
}
