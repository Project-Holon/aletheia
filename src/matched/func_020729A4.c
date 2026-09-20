/*
 * function: func_020729A4
 * address:  0x020729A4
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern u32 g_0214DEC0;

void func_020729A4(u32 mask)
{
    g_0214DEC0 &= ~mask;
}
