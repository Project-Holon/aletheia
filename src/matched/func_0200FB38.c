/*
 * function: func_0200FB38
 * address:  0x0200FB38
 * packet:   pkt_0200FB38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf accessor: if the u32 at +0x2c of the object at
 * g_0214617C is 1, set it to 2.
 *
 * symbols:
 *   g_0214617C     0x0214617C  data  a4
 */

extern unsigned int g_0214617C[];

void func_0200FB38(void)
{
    if (g_0214617C[11] == 1) {
        g_0214617C[11] = 2;
    }
}
