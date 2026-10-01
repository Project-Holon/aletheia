/*
 * function: func_021A56C0
 * address:  0x021A56C0
 * packet:   pkt_ov021_021A56C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

u32 func_021A3960(u32 x);
void func_0216D88C(u32 h, Vec021A56C0 *v);
void func_02163E58(u32 h, Vec021A56C0 *v, int *lim);

int func_021A56C0(u32 *p)
{
    u32 h = func_021A3960(p[3]);
    Vec021A56C0 v;
    int lim;

    func_0216D88C(h, &v);
    func_02163E58(h, &v, &lim);
    if (v.y <= lim)
        return 1;
    return 0;
}
