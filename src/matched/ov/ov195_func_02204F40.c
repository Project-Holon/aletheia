/*
 * function: func_02204F40
 * address:  0x02204F40
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 *
 * symbols:
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005DF8  0x02005DF8  thumb
 */
extern void func_02005E9C(void);
extern void func_02005DE4(int);
extern void func_02005DF8(int);

void func_02204F40(int a, int *p)
{
    int s = p[0xc];

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        func_02005E9C();
        func_02005DE4(0);
        func_02005DF8(6);
        p[0xc] = 4;
    }
}
