/*
 * function: SOCLi_SendCommandPacketToCtrlPipe
 * address:  0x0215CEFC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes the second argument on to both calls.
 *
 * symbols:
 *   SOCLi_GetCtrlPipe  0x0215CE9C  arm  ov009
 *   SOCLi_SendCommandPacket  0x0215CEB0  arm  ov009
 */

extern int SOCLi_GetCtrlPipe(const int *p, int b);
extern int SOCLi_SendCommandPacket(int a0, char *a1);

void SOCLi_SendCommandPacketToCtrlPipe(int a, int b)
{
    int v = SOCLi_GetCtrlPipe((const int *)a, b);

    SOCLi_SendCommandPacket(v, (char *)b);
}

