/*
 * function: func_021B66B0
 * address: 0x021B66B0
 * packet: pkt_ov172_021B66B0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B6724 0x021B6724 arm ov172
 *   func_021B672C 0x021B672C arm ov172
 *   func_021B6734 0x021B6734 arm ov172
 *   func_021B673C 0x021B673C arm ov172
 *   func_021B644C 0x021B644C thumb ov172
 *   g_021C88E0 0x021C88E0 data a4
 */
#include "../include/Obj02879.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int OS_IsRunOnTwl(void);
extern void func_021B6724(int);
extern int func_021B672C(void);
extern int func_021B6734(int);
extern void func_021B673C(int);
extern void func_021B644C(char *);
extern char *g_021C88E0;
void func_021B66B0(void)
{
    char *p = g_021C88E0;
    int one;
    func_021B6724(1);
    if ((OS_IsRunOnTwl() == 1 ? func_021B672C() : 0) == 1) {
        one = 1;
        if (func_021B6734(one) != 0) func_021B673C(one);
        if (((struct Obj02879 *)p)->f24 != 0) {
            ((struct Obj02879 *)p)->f24 = 0;
        } else if (((struct Obj02879 *)p)->f28 > 4) {
            if (*(void (**)(u32, u32))(p + 0x3C) != 0)
                (*(void (**)(u32, u32))(p + 0x3C))((*(u32 **)(p + 4))[((struct Obj02879 *)p)->f18], ((struct Obj02879 *)p)->f40);
            ((struct Obj02879 *)p)->f18 = (((struct Obj02879 *)p)->f18 + 1) % ((struct Obj02879 *)p)->f8;
        }
        if (((struct Obj02879 *)p)->f10 == 1) func_021B644C(p);
    }
}
