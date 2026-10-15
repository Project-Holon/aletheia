/*
 * function: GOAGetLastError
 * address:  0x0217ED54
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at +4 of the module state block.
 *
 * symbols:
 *   gGsSocketError  0x021AD0F4  data
 */

extern char gGsSocketError[];

int GOAGetLastError(int sock)
{
    return *(int *)(gGsSocketError + 4);
}

