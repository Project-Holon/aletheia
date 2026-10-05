/*
 * function: func_02206078
 * address:  0x02206078
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the func_022040E0 dependency tree: on a positive func_0220673C
 * probe it sets the +0x40 word and the +0x14 state word of the scene object
 * and notifies func_02206750; returns 1, else 0.
 *
 * symbols:
 *   func_0220673C  0x0220673C  thumb
 *   func_02206750  0x02206750  thumb
 */
int func_02206078(int *p)
{
    int func_0220673C(int *);
    void func_02206750(int *);

    if (func_0220673C(p) != 0) {
        p[0x10] = 1;
        p[5] = 0xc;
        func_02206750(p);
        return 1;
    }
    return 0;
}
