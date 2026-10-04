/*
 * function: func_021C7448
 * address: 0x021C7448
 * packet: pkt_ov208_021C7448
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C51A0 0x021C51A0 thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_021C7534 0x021C7534 thumb ov208
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj00147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C51A0(u8 *, u32);
extern void func_021C51C8(u32, int, u8 *);
extern void ov208_func_021C569C(u16 *, u8 *, int, int, int, int, u16);
extern void func_021C7534(u16 *, u8 *, int);
void func_021C7448(u16 *a0, u8 *p, int key)
{
    u16 old = ((struct Obj00147 *)p)->f550;
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6C8 == 0) {
        if (((struct Obj00147 *)p)->f548 >= 3) {
            ((struct Obj00147 *)p)->f550 = ((struct Obj00147 *)p)->f54E + ((struct Obj00147 *)p)->f548 - 1;
            ((struct Obj00147 *)p)->f550 = (u32)((struct Obj00147 *)p)->f550 % (u32)((struct Obj00147 *)p)->f548;
        }
    } else {
        if (((struct Obj00147 *)p)->f548 >= 3) {
            ((struct Obj00147 *)p)->f550 = ((struct Obj00147 *)p)->f54E + 1;
            ((struct Obj00147 *)p)->f550 = (u32)((struct Obj00147 *)p)->f550 % (u32)((struct Obj00147 *)p)->f548;
        }
    }
    if ((((struct Obj00147 *)p)->f124 != 0 && *(u32 *)&((struct Obj00147 *)p)->f94 == 0)
        || (((struct Obj00147 *)p)->f124 == 0 && *(u32 *)&((struct Obj00147 *)p)->fD8 == 0)
        || ((struct Obj00147 *)p)->f550 != old) {
        func_021C51A0(p + 0x94, ((struct Obj00147 *)p)->f8);
        func_021C51A0(p + 0xD8, ((struct Obj00147 *)p)->f8);
        a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
        b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
        ov208_func_021C569C(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
        if (a != 4) func_021C51C8(((struct Obj00147 *)p)->f98, 2, p);
        if (b != 4) func_021C51C8(((struct Obj00147 *)p)->fDC, 3, p);
    }
    func_021C7534(a0, p, key);
}
