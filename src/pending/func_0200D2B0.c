/*
 * function: func_0200D2B0
 * address:  0x0200D2B0
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0200D310 - not matched yet and this call at 0x0200D2B2 is the only branch to it in the image.  All 18 bytes right (verdict MATCH*: the listing extent runs two bytes long over the linker filler at 0x0200D2C2).
 */

typedef unsigned int u32;

extern u32 func_0200D310(void);

int func_0200D2B0(void)
{
    u32 v = func_0200D310();

    if (v >= 0x96)
        return 1;
    return 0;
}
