/*
 * function: func_0216CDC4
 * address:  0x0216CDC4
 * packet:   pkt_ov010_0216CDC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DEEC  0x0216DEEC  thumb  ov010
 *   func_0216D1C8  0x0216D1C8  thumb  ov010
 *   func_0216D040  0x0216D040  thumb  ov010
 *   func_0216D208  0x0216D208  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216D244  0x0216D244  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4FC  0x0216D4FC  thumb  ov010
 *   func_0216D0E8  0x0216D0E8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w[9];
} Rec;

extern u8 *func_0216DEEC(u32 a);
extern void func_0216D1C8(u8 *o, u32 a, u32 b);
extern void func_0216D040(u8 *o, Rec *r, u32 c, u32 a);
extern void func_0216D208(u8 *o);
extern int func_0216E51C(u8 *o);
extern void func_0216D548(u8 *o, u32 v);
extern int func_0216D4D4(u32 a, u32 v);
extern void func_0216D244(u32 a, u8 *o);
extern void func_0216D268(u32 a, u8 *o);
extern void func_0216E114(u8 *o);
extern u32 func_0216D67C(u8 *o);
extern int func_0216D4FC(u32 a0);
extern void func_0216D0E8(u8 *o, Rec *r, u32 z);

u8 *func_0216CDC4(u32 a, Rec *p, u32 b, u32 c)
{
    Rec r = *p;
    u8 *o;

    o = func_0216DEEC(a);
    func_0216D1C8(o, a, b);
    func_0216D040(o, &r, c, a);
    func_0216D208(o);
    if (func_0216E51C(o) == 1)
        func_0216D548(o, 640);
    if (func_0216D4D4(a, 0x10)) {
        func_0216D244(a, o);
        func_0216D268(a, o);
    }
    if (func_0216D4D4(a, 1))
        func_0216E114(o);
    func_0216D4FC(func_0216D67C(o));
    func_0216D0E8(o, &r, 0);
    return o;
}
