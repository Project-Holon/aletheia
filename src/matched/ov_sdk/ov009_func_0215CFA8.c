/*
 * function: SOCLi_ExecCommandPacketInCtrlPipe
 * address:  0x0215CFA8
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
 *   SOCLi_ExecCommandPacket  0x0215CF14  arm  ov009
 */

extern int SOCLi_GetCtrlPipe(const int *p, int b);
extern void SOCLi_ExecCommandPacket(int v, int b);

void SOCLi_ExecCommandPacketInCtrlPipe(int a, int b)
{
    int v = SOCLi_GetCtrlPipe((const int *)a, b);

    SOCLi_ExecCommandPacket(v, b);
}

