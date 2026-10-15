/*
 * function: CheckRcode
 * address:  0x0217EB00
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a negative argument at +0x4 of the module state object and returns the second.
 *
 * symbols:
 *   gGsSocketError  0x021AD0F4  data
 */

extern char gGsSocketError[];

int CheckRcode(int a, int b)
{
    if (a < 0) {
        *(int *)(gGsSocketError + 0x4) = a;
        return b;
    }
    return a;
}

