/*
 * function: INTRUDE_COMM_RecvShutdownRequest
 * address:  0x021736E0
 * packet:   pkt_021736E0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void INTRUDE_COMM_RecvShutdownRequest(int a, int b, int c, char *p)
{
    p[0x8fa] = 1;
}
