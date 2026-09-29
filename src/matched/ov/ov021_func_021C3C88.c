/*
 * function: func_021C3C88
 * address:  0x021C3C88
 * packet:   pkt_ov021_021C3C88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02005728  0x02005728  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern u32 func_02005728(u32 n);

void func_021C3C88(u32 *p, u32 *q)
{
    int x, y;
    u32 s0, s1;

    x = 0;
    if (func_02017E1C(p[0], 6, 0) == 0xe5)
        x = 1;
    y = 0;
    if (func_02017E1C(p[1], 6, 0) == 0xe5)
        y = 1;
    s0 = func_02017E1C(p[0], 0x70, 0);
    s1 = func_02017E1C(p[1], 0x70, 0);
    if (x || y) {
        if (func_02005728(2) == 0)
            return;
    }
    if (x && y) {
        if (func_02005728(2) == 0) {
            q[3] = s0;
            q[0x14] = 1;
        } else {
            q[3] = s1;
            q[0x15] = 1;
        }
    } else if (x) {
        q[3] = s0;
        q[0x14] = 1;
    } else if (y) {
        q[3] = s1;
        q[0x15] = 1;
    }
}
