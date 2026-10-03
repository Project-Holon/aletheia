/*
 * function: func_021F0AC0
 * address:  0x021F0AC0
 * packet:   pkt_ov032_021F0AC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0AC0  0x021F0AC0  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021F0A98  0x021F0A98  thumb  ov032
 *   func_021F201C  0x021F201C  thumb  ov032
 */

extern void func_0201EFA4(int a, int b, int c, int d, int e, int f);
extern void func_021F0A98(char *p, unsigned a);
extern void func_021F201C(char *p, char *q, int r, int s, int t, int u, int v, int w);

void func_021F0AC0(char *p)
{
    func_0201EFA4(*(int *)(p + 0x110), 0, *(unsigned char *)(p + 0x7b), 2, 1, 1);
    func_021F0A98(p, 0);
    func_021F201C(p, p + 0x110 + 0x94, *(int *)(p + 0x11c), 4, 0, 1, 0x3DC1, 0);
}
