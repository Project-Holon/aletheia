/*
 * function: func_0204ABBC
 * address:  0x0204ABBC
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204AB84  0x0204AB84  arm
 *   func_020637B4  0x020637B4  arm
 *
 * Snapshot one actor record into a local 36-byte buffer and hand it to
 * func_020637B4 with mode 1, or mode 2 when the second argument is set.
 */

typedef unsigned int u32;

struct Rec {
    u32 w[9];
};

extern void func_0204AB84(u32 idx, struct Rec *dst);
extern int func_020637B4(int *p, int i);

void func_0204ABBC(u32 idx, u32 flag)
{
    struct Rec buf;
    u32 mode = 1;

    if (flag != 0) {
        mode = 2;
    }
    func_0204AB84(idx, &buf);
    func_020637B4((int *)(&buf), mode);
}
