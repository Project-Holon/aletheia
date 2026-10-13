/*
 * function: BTL_SERVER_SetHandler
 * address: 0x021BABEC
 * packet: pkt_ov093_021BABEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */

void BTL_SERVER_SetHandler(int *p, void *f)
{
 p[0] = (int)f;
 p[1] = 0;
}
