/*
 * function: func_02205168
 * address:  0x02205168
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to func_02205100.  A missing
 * +0x60 pointer reports success without probing.
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 *   func_02205100  0x02205100  thumb
 */
extern int func_0204B98C(int);
extern void func_02205100(int, int *);

int func_02205168(int a, int *p)
{
    unsigned char i;

    if (p[0x18] != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (func_0204B98C(p[0x12 + i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            func_02205100(a, p);
        return ok;
    }
    return 1;
}
