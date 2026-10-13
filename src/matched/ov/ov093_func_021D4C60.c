/*
 * function: BTL_NET_HasServerCmd
 * address:  0x021D4C60
 * packet:   pkt_ov093_021D4C60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet  0x021F3B88  data  ov093
 */

extern unsigned char *gBtlNet;

unsigned char BTL_NET_HasServerCmd(void)
{
    return gBtlNet[13];
}
