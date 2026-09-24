/*
 * function: func_0217ED38
 * address:  0x0217ED38
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word the call fills in, or -1.
 *
 * symbols:
 *   func_0215FAD0  0x0215FAD0  arm  ov009
 */

extern int func_0215FAD0(int a, int *out);

int func_0217ED38(int a)
{
    int v;

    if (func_0215FAD0(a, &v) == 0) {
        return -1;
    }

    return v;
}

