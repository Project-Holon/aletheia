/*
 * function: IRCNET_SetFilter
 * address: 0x021799C0
 * packet: pkt_ov015_021799C0
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0217AB40 0x0217AB40 data a4
 */
extern unsigned char d_0217AB40[];
void IRCNET_SetFilter(int a) { *(int *)(d_0217AB40+0x48)=a; }
