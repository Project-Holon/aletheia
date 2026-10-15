/*
 * function: gsirealloc
 * address:  0x0217EAC8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the second word of the table at 0x021A3730 on the two arguments.
 *
 * symbols:
 *   gGsMemoryFuncs  0x021A3730  data
 */

extern char gGsMemoryFuncs[];

void gsirealloc(int a, int b)
{
    (*(void (**)(int, int))(gGsMemoryFuncs + 8))(a, b);
}

