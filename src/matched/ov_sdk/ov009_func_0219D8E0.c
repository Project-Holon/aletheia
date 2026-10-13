/*
 * function: SBEngineHaltUpdates
 * address:  0x0219D8E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the two blocks inside the argument.
 *
 * symbols:
 *   FIFOClear  0x0219D5B0  arm  ov009
 */

extern void FIFOClear(int *p);

void SBEngineHaltUpdates(char *p)
{
    FIFOClear((int *)(p + 0x14));
    FIFOClear((int *)(p + 8));
}

