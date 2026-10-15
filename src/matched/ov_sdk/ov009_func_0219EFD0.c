/*
 * function: ServerBrowserThink
 * address:  0x0219EFD0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Releases the object and the block 0x60 bytes in.
 *
 * symbols:
 *   NNThink  0x0219A4A4  arm  ov009
 *   SBQueryEngineThink  0x0219DE88  arm  ov009
 *   SBListThink  0x021A1928  arm  ov009
 */

extern void NNThink(void *p);
extern void SBQueryEngineThink(void *p);
extern int SBListThink(int *p);

int ServerBrowserThink(char *p)
{
    NNThink(p);
    SBQueryEngineThink(p);
    return SBListThink((int *)(p + 0x60));
}

