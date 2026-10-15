/*
 * function: gsifree
 * address:  0x0217EAE0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the second word of the table at 0x021A3730 on the argument.
 *
 * symbols:
 *   gGsMemoryFuncs  0x021A3730  data
 */

extern char gGsMemoryFuncs[];

void gsifree(void *p)
{
    if (p == 0) {
        return;
    }

    (*(void (**)(void *))(gGsMemoryFuncs + 4))(p);
}

