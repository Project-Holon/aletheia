/*
 * function: func_021B90F8
 * address:  0x021B90F8
 * packet:   pkt_ov091_021B90F8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBBA0  0x021BBBA0  thumb  ov091
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02041570  0x02041570  arm
 *   func_020355C4  0x020355C4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021BBBA0(int unused, int *q);
extern void func_021BB7A4(u8 *p, int v);
extern int func_021B9A84(u8 *p);
extern int func_021B9AB4(u8 *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0207D63C(u16 *r, int a, int b, int c, int d);
extern void func_02041570(int channel, u16 val);
extern u8 func_020355C4(void);

#define W(o) (*(int *)(p + (o)))

void func_021B90F8(u8 *p)
{
    func_021BBBA0((int)p, (int *)W(0x154));
    func_021BB7A4(p, W(0x150));
    if (func_021B9A84(p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
    if (W(0x3c) != 4 && W(0x3c) != 5) {
        func_0207D63C((u16 *)0x04000050, 0x14, 8, 0x10, 0xa);
        W(0x10) = 0;
    }
    func_02041570(0, 0);
    W(8) = func_020355C4();
}
