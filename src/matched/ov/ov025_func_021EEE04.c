/*
 * function: func_021EEE04
 * address:  0x021EEE04
 * packet:   pkt_ov025_021EEE04
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     idx is narrow (u16/s16/u8 all give EXACT; int puts its home store
 *           third instead of first): func_021A21C8 only forwards it, so no
 *           callee fixes the exact width. const on the two tables lets the
 *           indexed loads hoist out of the loop past the stores through e.
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_0204B404  0x0204B404  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   d_021EF780     0x021EF780  data   a4
 *   d_021EF770     0x021EF770  data   a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void func_0204B908(int, u16);
extern void func_0204B404(int, Pt *, int);
extern int *func_021A21B8(int);
extern int func_021A21C8(int, int);
extern int *func_021A2630(int);
extern int func_021A2638(int);
extern const int d_021EF780[];
extern const int d_021EF770[];

void func_021EEE04(int a, int n, u16 idx)
{
    int *q;
    int k;
    int i;
    int obj;
    int *e;
    int h;
    int m;
    Pt pt;

    q = func_021A21B8(a);
    if (++q[1] >= 0x400) {
        q[1] = 0;
    }
    k = q[1] / 256;
    for (i = 0; i < n; i++) {
        obj = func_021A21C8(a, idx);
        if (obj == 0) {
            return;
        }
        e = func_021A2630(obj);
        h = func_021A2638(obj);
        e[0] = 0;
        e[1] = func_020056EC(3) + 9;
        m = func_020056EC(4);
        func_0204B908(h, m);
        e[4] = (m + 1) * d_021EF770[k];
        e[2] = d_021EF780[k] * (m + 1);
        e[3] = 0;
        if (m == 3) {
            e[4] = e[4] + d_021EF770[k];
            e[2] = e[2] + d_021EF780[k];
        }
        e[5] = d_021EF770[k];
        pt.x = -func_020056EC(0x18);
        pt.y = func_020056EC(0xA8) - 0x20;
        func_0204B404(h, &pt, 0);
    }
}
