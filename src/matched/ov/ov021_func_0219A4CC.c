/*
 * function: func_0219A4CC
 * address:  0x0219A4CC
 * packet:   pkt_ov021_0219A4CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219A3D8  0x0219A3D8  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0219A3D8(u32, int *);
extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D86C(void *p);
extern int func_021641F8(u16);

int func_0219A4CC(u32 a, u32 b)
{
    int r[4];
    int x;
    int y;
    func_0219A3D8(a, r);
    x = func_0216D83C((void *)a) + func_021641E8((u16)b);
    y = func_0216D86C((void *)a) + func_021641F8(b);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}
