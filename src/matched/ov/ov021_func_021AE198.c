/*
 * function: func_021AE198
 * address:  0x021AE198
 * packet:   pkt_ov021_021AE198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021AE348  0x021AE348  thumb  ov021
 *   func_021AE7A8  0x021AE7A8  thumb  ov021
 */

typedef short s16;

typedef unsigned int   u32;
extern void *func_0216D67C(void *a0);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D828(int a, int *b);
extern int func_021AE348(int idx, int a, const s16 *p, const s16 *q);
extern int func_021AE7A8(u32 a, u32 dir, int n, void *p);

int func_021AE198(int a, int b, int c, int d)
{
    int q[2];
    int p[2];
    int h;
    int r;

    h = (int)func_0216DE94(func_0216D67C((void *)a), 0xff);
    if (h == 0)
        return -1;
    func_0216D828(h, p);
    func_0216D828(a, q);
    r = func_021AE348(b, (s16)c, (const s16 *)q, (const s16 *)p);
    if (r != -1) {
        if (func_021AE7A8(a, b, r, (void *)d) == 1)
            r = -1;
    }
    return r;
}
