/*
 * file:     unit_068998F4.c
 * unit:     yes
 * function: func_068998F4, func_06899900
 * address:  0x068998F4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   func_021C7CF4  0x021C7CF4  thumb
 *   func_021C8010  0x021C8010  thumb
 *   func_021C814C  0x021C814C  thumb
 *   func_021C83D4  0x021C83D4  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   d_0689D6F8 0x0689D6F8 data ov095 a4
 */
#include "../../matched/include/Obj06335.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int a);
extern int func_021C814C(int a, int b);
extern int func_021C83D4(int a);
extern int func_021B9A40(int a);
extern int func_021C7CF4(int a, int b);
extern int BTL_POKEPARAM_HasType(int a, int b);
extern u8 *func_021C88A4(int a, int b, int c);
extern int func_021C8010(int a, int b);
extern void func_021C88C8(int a, u8 *q);
extern int BTL_CALC_DivideMaxHpMin1(int a, int b);
extern void func_021C8838(u8 *p, int n, int c);
extern void func_021C8860(u8 *p, int v);
unsigned char *func_068998F4(u32 *p);
void func_06899900(int a0, int p, int x);
extern unsigned char d_0689D6F8[];

/*
 * Follower after the 068998E4 linker veneer; ends at 06899900.
 */
unsigned char *func_068998F4(u32 *p)
{
    *p = 1;
    return d_0689D6F8;
}


void func_06899900(int a0, int p, int x)
{
    u8 v;
    int w;
    u8 *t;

    v = BTL_EVENT_GetVar(2);
    if (v != 0x1f && func_021C814C(p, v) != 0 && func_021C83D4(p) == 0
        && x == func_021B9A40(v)) {
        w = func_021C7CF4(p, v);
        if (BTL_POKEPARAM_HasType(w, 9) == 0) {
            t = func_021C88A4(p, 0x37, v);
            t[6] = func_021C8010(p, v);
            t[7] = 6;
            ((struct Obj06335 *)t)->f4 = 0x28e;
            func_021C88C8(p, t);
            t = func_021C88A4(p, 7, 0x1f);
            t[6] = v;
            ((struct Obj06335 *)t)->f4 = BTL_CALC_DivideMaxHpMin1(w, 8);
            func_021C8838(t + 0xc, 2, 0x484);
            func_021C8860(t + 0xc, v);
            func_021C88C8(p, t);
        }
    }
}
