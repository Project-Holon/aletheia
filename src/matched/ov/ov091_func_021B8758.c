/*
 * function: func_021B8758
 * address:  0x021B8758
 * packet:   pkt_ov091_021B8758
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021B9E20  0x021B9E20  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021BB2C0  0x021BB2C0  thumb  ov091
 *   func_021BB464  0x021BB464  thumb  ov091
 *   func_021BA288  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7B98  0x021B7B98  thumb  ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BB7A4(void *p, u32 *s);
extern void *func_0201AB28(void *p, u32 idx);
extern u32   func_02017E1C(void *obj, u32 key, u32 off);
extern void  func_02017E40(void *obj, u32 key, u32 v);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021B9E20(u8 *p);
extern void  func_021B8F68(u8 *p, int v);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021BB2C0(u8 *a, u8 *s);
extern unsigned short func_021BB464(int unused, unsigned short *p);
extern void func_021BA288(u8 *p);
extern void  func_020061E4(u32 id);
extern void  func_021B7B98(u8 *p);

void func_021B8758(u8 *p)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3) {
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        a = func_02017E1C((void *)W(0x38), 0xa0, 0);
        b = func_02017E1C((void *)W(0x38), 0xa1, 0);
        if (W(0x2c) == W(0x34) || a == 0 || b == a) {
            func_021B9788(p, 0x64, 1, (int)func_021B9E20);
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1dc), 0);
            ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
            return;
        }
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        p[0xc] = 10;
        *(u16 *)(p + 0x11c) = func_021BB464((int)p, (short unsigned int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x120) = (u32)func_021BA288;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        o = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
        c = func_02017E1C(o, 0xa1, 0);
        d = func_02017E1C(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            func_02017E40(o, 0xa0, d - (b - a));
        } else {
            func_02017E40(o, 0xa0, d - e);
        }
        ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
        W(0x2c) = W(0x34);
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        func_020061E4(0x56f);
        return;
    }
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x34) = 9;
    ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
    func_021B7B98(p);
    func_020061E4(0x551);
}
