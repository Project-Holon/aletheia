/*
 * function: func_0215E23C
 * address:  0x0215E23C
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0215E2C0  0x0215E2C0  arm  ov009
 *
 * Pull a count out of the object at +0xa4, clamped to `n` (and, when it came
 * back short, to `m`) -- below `m` the loop instead either gives up with 0 or
 * pumps func_020857B0 on the +0x104 channel, depending on the low bit of the
 * fifth argument.  The success path copies the u16 at +0x100 out.  The whole
 * scan runs inside a func_02087988/func_0208799C interrupt bracket.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_0215E23C(void *a, int n, int m, int *out, int f5)
{
    u32 *base;
    int st;
    int v;
    int flag;

    base = *(u32 **)((u8 *)a + 0xa4);
    if (m > n)
        m = n;
    st = func_02087988();
    flag = f5 & 1;
    for (;;) {
        v = func_0215E2C0(a);
        if (v >= m) {
            if (v >= n)
                v = n;
            *out = *(u16 *)((u8 *)base + 0x100);
            break;
        }
        if (flag == 0) {
            v = 0;
            break;
        }
        func_020857B0((u8 *)base + 0x104);
    }
    func_0208799C(st);
    return v;
}
