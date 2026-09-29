/*
 * function: func_021F3C84
 * address:  0x021F3C84
 * packet:   pkt_ov056_021F3C84
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F36D4  0x021F36D4  thumb  ov056
 *   func_0204784C  0x0204784C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021F36D4(u32 a);
extern void func_0204784C(u32 h, u16 i, int *v);

int func_021F3C84(u32 *p)
{
    int r;
    int lim;
    int ret;

    r = func_021F36D4(p[5]);
    lim = p[31] + 0x1000;
    if (r <= lim) {
        ret = 1;
        p[31] = r - 0x1000;
    } else {
        ret = 0;
        p[31] = lim;
    }
    func_0204784C(p[7], 0, (int *)&p[31]);
    func_0204784C(p[7], 1, (int *)&p[31]);
    return ret;
}
