/*
 * function: func_021BA388
 * address:  0x021BA388
 * packet:   pkt_ov217_021BA388
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA3B4  0x021BA3B4  thumb  ov217
 */

typedef unsigned int   u32;
extern u32 func_021BA3B4(u32 a0, u32 a1);

void func_021BA388(char *self, int d)
{
    int n = *(int *)(self + 0x28);
    do {
        n = (n + d + 2) % 2;
    } while (!func_021BA3B4((u32)self, n));
    *(int *)(self + 0x28) = n;
}
