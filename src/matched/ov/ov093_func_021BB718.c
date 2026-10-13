/*
 * function: BTL_SERVER_SendCommand
 * address:  0x021BB718
 * packet:   pkt_021BB718
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 */

typedef unsigned char  u8;
void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);

void BTL_SERVER_SendCommand(int a, int b)
{
    BTL_SERVER_SendCommandData((u8 *)a, b, 0, 0);
}
