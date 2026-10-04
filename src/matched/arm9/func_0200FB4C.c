/*
 * function: func_0200FB4C
 * address:  0x0200FB4C
 * packet:   pkt_0200FB4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: if the u32 at +0x2c of the object at g_0214617C is
 * not 2, store the argument at +0x60, set two flag bytes of the object at
 * g_021461BC, and set +0x2c to 2.
 *
 * symbols:
 *   g_0214617C     0x0214617C  data  a4
 *   g_021461BC     0x021461BC  data  a4
 */

extern unsigned int g_0214617C[];
extern unsigned char g_021461BC[];

void func_0200FB4C(unsigned int x)
{
    if (g_0214617C[11] != 2) {
        g_0214617C[24] = x;
        g_021461BC[0x1a] = 1;
        g_021461BC[0x19] = 1;
        g_0214617C[11] = 2;
    }
}
