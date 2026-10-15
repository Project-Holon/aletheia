/*
 * function: SOCLi_ExecCommandPacketInSendPipe
 * address:  0x0215CF98
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0xa4 of the object.
 *
 * symbols:
 *   SOCLi_ExecCommandPacket  0x0215CF14  arm
 */

extern void SOCLi_ExecCommandPacket(int v);

void SOCLi_ExecCommandPacketInSendPipe(const int *p)
{
    SOCLi_ExecCommandPacket(p[0x29]);
}

