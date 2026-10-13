/*
 * function: func_0219EFD0
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
 *   func_0219A4A4  0x0219A4A4  arm  ov009
 *   SBQueryEngineThink  0x0219DE88  arm  ov009
 *   func_021A1928  0x021A1928  arm  ov009
 */

extern void func_0219A4A4(void *p);
extern void SBQueryEngineThink(void *p);
extern int func_021A1928(int *p);

int func_0219EFD0(char *p)
{
    func_0219A4A4(p);
    SBQueryEngineThink(p);
    return func_021A1928((int *)(p + 0x60));
}

