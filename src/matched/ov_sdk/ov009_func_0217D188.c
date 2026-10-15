/*
 * function: gsiDebugCallback
 * address:  0x0217D188
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that drops the middle arguments and keeps the last two.
 *
 * symbols:
 *   VPrintf  0x0218402C  arm
 */

extern void VPrintf(char *format, char *args);

void gsiDebugCallback(int a, int b, int c, int d, int e)
{
    VPrintf((char *)d, (char *)e);
}

