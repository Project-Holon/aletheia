/*
 * function: func_021A4F58
 * address:  0x021A4F58
 * packet:   pkt_ov021_021A4F58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only r0/r1 swap around the v.y -= 0x8000 (original keeps v.y
 * in r0 and the constant in r1). Compare order, decl order, compound forms tried.
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

u32 func_021A3960(u32 x);
void func_0216D88C(u32 h, Vec021A4F58 *v);
void func_02163E58(u32 h, Vec021A4F58 *v, int *lim);
void func_0216D570(u32 h);
void func_0216D89C(u32 h, Vec021A4F58 *v);

void func_021A4F58(u32 *p)
{
    u32 h = func_021A3960(p[3]);
    Vec021A4F58 v;
    int lim;

    func_0216D88C(h, &v);
    func_02163E58(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            func_0216D570(h);
            p[7] = 1;
        }
        func_0216D89C(h, &v);
        p[0] = 7;
    }
}
