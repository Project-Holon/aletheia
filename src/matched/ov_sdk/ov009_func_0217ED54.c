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
 *   g_021AD0F4  0x021AD0F4  data
 */

extern char g_021AD0F4[];

int GOAGetLastError(int sock)
{
    return *(int *)(g_021AD0F4 + 4);
}

