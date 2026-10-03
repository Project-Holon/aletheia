/*
 * function: func_021D0914
 * address:  0x021D0914
 * packet:   pkt_ov021_021D0914
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 */

typedef short s16;

extern int func_0216D5F8(int a);
extern int func_0216D55C(int a, int b);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
typedef unsigned int   u32;
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern void func_0207CDB8(s16 *a, s16 *b);

int func_021D0914(int a, s16 *v)
{
    int r;

    r = func_0216D5F8(a);
    if (func_0216D55C(a, 0x1000 * 2) == 0) {
        v[1] = 0;
        v[0] = func_021641E8(r);
        v[2] = func_021641F8(r);
        v[0] = v[0] << 16;
        v[2] = v[2] << 16;
    } else {
        func_0219E784(a, r, v);
        v[1] = 0;
    }
    func_0207CDB8(v, v);
    return r;
}
