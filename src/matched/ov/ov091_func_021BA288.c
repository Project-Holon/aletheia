/*
 * function: func_021BA288
 * address:  0x021BA288
 * packet:   pkt_ov091_021BA288
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021BA318  0x021BA318  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void *func_0201AB28(void *list, int idx);
extern u32   func_02017E1C(void *obj, u32 key, u32 off);
extern void  func_02017E40(void *obj, u32 key, u32 v);
extern void  func_021BA318();

void func_021BA288(u8 *p)
{
    void *o1;
    void *o2;
    u32 b, c, d, e;

    o1 = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
    func_02017E1C(o1, 0xa0, 0);
    b = func_02017E1C(o1, 0xa1, 0);
    o2 = func_0201AB28((void *)*(u32 *)W(0x280), ((u32 *)W(0x280))[0x3c / 4]);
    c = func_02017E1C((void *)W(0x38), 0xa0, 0);
    d = func_02017E1C((void *)W(0x38), 0xa1, 0);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    e = c + b / 5;
    if (e > d) {
        func_02017E40(o2, 0xa0, d);
    } else {
        func_02017E40(o2, 0xa0, e);
    }
    W(0x120) = (u32)func_021BA318;
    p[0xc] = 10;
    W(0x24) = 1;
}
