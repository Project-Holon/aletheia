/*
 * function: func_0219B200
 * address:  0x0219B200
 * packet:   pkt_ov021_0219B200
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219B120  0x0219B120  thumb  ov021
 *   func_0219B0D8  0x0219B0D8  thumb  ov021
 *   func_0219B13C  0x0219B13C  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */

extern int *func_0219B120(int id);
extern int func_0219B0D8(int *tbl, int v);
typedef unsigned int   u32;
extern int func_0219B13C(u32 a);
extern int func_0216D67C(int a);
extern int func_0216DEE0(int a);
extern int func_0216D83C(int a);
extern int func_0216D86C(int a);

int func_0219B200(int a, int id, int end)
{
    int *tbl;
    int n;
    int t;
    int i;
    int o;
    int ax;
    int ay;
    int ox;
    int oy;
    int dx;
    int dy;

    tbl = func_0219B120(id);
    n = func_0219B0D8(tbl, end);
    if (n == 1) {
        return 9;
    }
    t = func_0219B13C(a);
    if (t != 9) {
        i = 0;
        do {
            if (t == tbl[i]) {
                return t;
            }
            i++;
        } while (i < n);
        o = func_0216DEE0(func_0216D67C(a));
        dx = 9;
        dy = 9;
        ax = func_0216D83C(a);
        ay = func_0216D86C(a);
        ox = func_0216D83C(o);
        oy = func_0216D86C(o);
        if (ax > ox) {
            dx = 2;
        } else if (ax < ox) {
            dx = 3;
        }
        if (ay > oy) {
            dy = 0;
        } else if (ay < oy) {
            dy = 1;
        }
        i = 0;
        if (dx == 9) {
            do {
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        } else if (dy == 9) {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                i++;
            } while (i < n);
        } else {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        }
        return 9;
    }
    return t;
}
