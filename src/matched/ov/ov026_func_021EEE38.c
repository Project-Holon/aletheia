/*
 * function: func_021EEE38
 * address:  0x021EEE38
 * packet:   pkt_ov026_021EEE38
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEE38  0x021EEE38  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   d_021EFD08     0x021EFD08  data  ov026  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void func_0204B908(int, u16);
extern int *func_021A21B8(int);
extern int func_021A21C8(int, int);
extern int *func_021A2630(int);
extern int func_021A2638(int);
extern void func_021A26C4(int, Pt *);
extern int d_021EFD08[];

void func_021EEE38(int a, int n, int idx)
{
    int i;
    int *w;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
    Pt pt;

    w = func_021A21B8(a);
    for (i = 0; i < n; i++) {
        obj = func_021A21C8(a, idx);
        if (obj == 0) {
            return;
        }
        e = func_021A2630(obj);
        h = func_021A2638(obj);
        r = func_020056EC(0);
        m = r % 3;
        func_0204B908(h, m);
        e[2] = e[4] = (r & 15) + (m + 1) * 14;
        e[4] = d_021EFD08[w[2] / 60] * e[4] / 10;
        e[2] = d_021EFD08[w[2] / 60] * e[2] / 10;
        e[3] = 0;
        pt.x = r % 0x180 - 0x80;
        pt.y = r % 0x28 - 0x50;
        func_021A26C4(obj, &pt);
    }
}
