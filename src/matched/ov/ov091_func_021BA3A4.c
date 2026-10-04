/*
 * unit:     yes
 * function: func_021BA3A4, func_021BA444
 * address:  0x021BA3A4
 * packet:   pkt_ov091_021BA3A4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb ov091
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02017E40  0x02017E40  thumb
 *   func_021BB2C0  0x021BB2C0  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021B9E20  0x021B9E20  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021BA454  0x021BA454  thumb ov091
 */
#include "../include/Obj13245.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BB7A4(void *p, u32 *s);
extern int   func_02009020(void *obj, int v);
struct Sub02008F80Obj;
extern void *func_02008F08(int a0);
extern u32   func_02017E1C(void *obj, u32 key, u32 off);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void  func_020307B0(void *p);
extern void  func_02017E40(void *obj, u32 key, u32 v);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021B9E20(u8 *p);
extern void func_021B9804(u8 *p, int a1);
extern void func_021BA454(u8 *a, int k);
extern void  func_021BA444();

void func_021BA3A4(u8 *p, u32 state)
{
    int r;
    void *buf;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        r = func_02009020((void *)((u32 *)W(0x280))[2], 0);
        if (r >= 0) {
            buf = func_02008F08(((struct Obj13245 *)p)->f0);
            func_02017E1C((void *)W(0x38), 0xa7, (u32)buf);
            func_0200903C((void *)((u32 *)W(0x280))[2], 0, r, buf);
            func_020307B0(buf);
            func_02017E40((void *)W(0x38), 6, 0);
            func_021BB2C0(p, (u8 *)(((u32 *)(p + 0x160))[W(0x2c)]));
            func_021B9788(p, 0x1a, 1, (int)func_021B9E20);
        } else {
            func_021B9788(p, 0x1e, 1, (int)func_021B9E20);
        }
        return;
    }
    func_021B9788(p, 0x1b, 0, (int)func_021BA444);
}

void func_021BA444(u8 *p)
{
    func_021B9804(p, (int)func_021BA454);
}
