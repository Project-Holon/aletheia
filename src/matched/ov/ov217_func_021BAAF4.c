/*
 * function: func_021BAAF4
 * address:  0x021BAAF4
 * packet:   pkt_021BAAF4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_021C29D8(void *a0);

void func_021BAAF4(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29D8((void *)p[i + 0x0E]);
}
