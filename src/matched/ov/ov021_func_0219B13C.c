/*
 * function: func_0219B13C
 * address:  0x0219B13C
 * packet:   pkt_ov021_0219B13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0219B074  0x0219B074  thumb  ov021
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D4FEC  0x021D4FEC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0216D5A8(u8 *p);
extern int func_0219B074(int a);
extern u16 func_0216D5A0(void *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D854(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D63C(char *a0, int a1);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern u32 d_021D4FEC[];

int func_0219B13C(u32 a)
{
    int k;
    u32 v;
    u32 e;
    int i;
    u32 o;
    int ox, oy, ax, ay, r;
    int x0, x1, y0, y1;

    k = func_0216D5A8((u8 *)a);
    if (k != 1 && k != 2) {
        return 9;
    }
    if (func_0219B074(a) == 0) {
        return 9;
    }
    i = 0;
    v = func_0216D5A0((void *)a);
    do {
        e = d_021D4FEC[i++];
    } while (e != v && e != 0xFF);
    if (v != e) {
        return 9;
    }
    o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    if (o == 0) {
        return 9;
    }
    if (func_0216D854((void *)o) != func_0216D854((void *)a)) {
        return 9;
    }
    ox = func_0216D83C((void *)o);
    oy = func_0216D86C((void *)o);
    r = func_0216D63C((char *)a, 0);
    ax = func_0216D83C((void *)a);
    ay = func_0216D86C((void *)a);
    x0 = ax - r;
    x1 = ax + r;
    y0 = ay - r;
    y1 = ay + r;
    if (y0 <= oy && y1 >= oy && x0 <= ox && x1 >= ox) {
        return func_021642B4(ax, ay, ox, oy);
    }
    return 9;
}
