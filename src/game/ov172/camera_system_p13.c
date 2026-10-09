/*
 * file:     camera_system_p13.c
 * unit:     yes
 * function: func_021B6620, func_021B662C
 * address:  0x021B6620
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B65D8  0x021B65D8  thumb  ov172
 *   func_02085D3C 0x02085D3C arm
 *   func_021B6698 0x021B6698 arm ov172
 *   func_021B66A0 0x021B66A0 arm ov172
 *   func_021B66A8 0x021B66A8 arm ov172
 *   func_021B644C 0x021B644C thumb ov172
 *   func_02088234 0x02088234 arm
 *   g_021C88E0 0x021C88E0 data a4
 */
#include "../../matched/include/Obj03311.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_021B65D8(void);
extern int func_02085D3C(void);
extern int func_021B6698(u32);
extern void func_021B66A0(void);
extern void func_021B66A8(void);
extern void func_021B644C(char *);
extern void func_02088234(void);
void func_021B6620(int x);
void func_021B662C(void);
extern char *g_021C88E0;


/*
 * Delegate to func_021B65D8 unless the argument is 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6620(int x)
{
    if (x != 7) {
        func_021B65D8();
    }
}

void func_021B662C(void)
{
    char *p = g_021C88E0;
    u32 v;
    if (((struct Obj03311 *)p)->f10 != 0) {
        if (((struct Obj03311 *)p)->f28 <= 30) ++((struct Obj03311 *)p)->f28;
        if (((struct Obj03311 *)p)->f20 != 0) {
            v = ((struct Obj03311 *)p)->f2C;
            if ((func_02085D3C() == 1 ? func_021B6698(v) : 7) == 7)
                func_02088234();
            ((struct Obj03311 *)p)->f28 = 0;
            ((struct Obj03311 *)p)->f20 = 0;
        }
        if (((struct Obj03311 *)p)->f1C != 0) {
            func_021B644C(p);
            if (func_02085D3C() == 1) func_021B66A0();
            if (func_02085D3C() == 1) func_021B66A8();
            ((struct Obj03311 *)p)->f1C = 0;
        }
    }
}
