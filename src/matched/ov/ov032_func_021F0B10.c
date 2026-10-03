/*
 * function: func_021F0B10
 * address:  0x021F0B10
 * packet:   pkt_ov032_021F0B10
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0B10  0x021F0B10  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021F0A98  0x021F0A98  thumb  ov032
 *   func_021F201C  0x021F201C  thumb  ov032
 */

extern void func_0201EFA4(int a, int b, int c, int d, int e, int f);
extern void func_021F0A98(char *p, unsigned a);
extern void func_021F201C(char *p, char *q, int r, int s, int t, int u, int v, int w);

void func_021F0B10(char *p, int a, int b)
{
    func_0201EFA4(*(int *)(p + 0x110), 0, *(int *)(p + 0x2d4), 5, 0, 1);
    func_021F0A98(p, a);
    func_021F201C(p, p + 0x110 + 0x80, *(int *)(p + 0x11c), 0, 4, 0, 0x3C40, b);
}
