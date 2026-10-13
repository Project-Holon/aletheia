/*
 * function: func_021B662C
 * address: 0x021B662C
 * packet: pkt_ov172_021B662C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B6698 0x021B6698 arm ov172
 *   func_021B66A0 0x021B66A0 arm ov172
 *   func_021B66A8 0x021B66A8 arm ov172
 *   func_021B644C 0x021B644C thumb ov172
 *   func_02088234 0x02088234 arm
 *   g_021C88E0 0x021C88E0 data a4
 */
#include "../include/Obj03311.h"
typedef unsigned int u32;
extern int OS_IsRunOnTwl(void);
extern int func_021B6698(u32);
extern void func_021B66A0(void);
extern void func_021B66A8(void);
extern void func_021B644C(char *);
extern void func_02088234(void);
extern char *g_021C88E0;
void func_021B662C(void)
{
    char *p = g_021C88E0;
    u32 v;
    if (((struct Obj03311 *)p)->f10 != 0) {
        if (((struct Obj03311 *)p)->f28 <= 30) ++((struct Obj03311 *)p)->f28;
        if (((struct Obj03311 *)p)->f20 != 0) {
            v = ((struct Obj03311 *)p)->f2C;
            if ((OS_IsRunOnTwl() == 1 ? func_021B6698(v) : 7) == 7)
                func_02088234();
            ((struct Obj03311 *)p)->f28 = 0;
            ((struct Obj03311 *)p)->f20 = 0;
        }
        if (((struct Obj03311 *)p)->f1C != 0) {
            func_021B644C(p);
            if (OS_IsRunOnTwl() == 1) func_021B66A0();
            if (OS_IsRunOnTwl() == 1) func_021B66A8();
            ((struct Obj03311 *)p)->f1C = 0;
        }
    }
}
