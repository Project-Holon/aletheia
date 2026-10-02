/*
 * function: func_021BF358
 * address:  0x021BF358
 * packet:   pkt_ov210_021BF358
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 * Addresses are Black-image addresses.
 */

extern void func_0204B3B4(int h);

void func_021BF358(int p, int i)
{
    int o = i * 4;
    int *q = (int *)(p + 0x28);

    if (*(int *)((int)q + o) != 0) {
        func_0204B3B4(*(int *)((int)q + o));
        *(int *)((int)q + o) = 0;
    }
}
