/*
 * file:     unit_068995A4.c
 * unit:     yes
 * function: func_068995A4, func_068995B0
 * address:  0x068995A4
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
 *   func_021C8234  0x021C8234  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   data_0689D740 0x0689D740 data a4
 *   func_06898DE0  0x06898DE0  thumb
 */
#include "../../matched/include/Obj13633.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_06898DE0(int a, u32 b);
extern int BTL_EVENT_GetVar(int a);
extern int func_021B9A40(int a);
extern int func_021C8234(int a, int b);
extern u8 *func_021C88A4(int p, int n, int m);
extern int func_021C7CF4(int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(int a, int b);
extern void func_021C8838(u8 *p, int n, int c);
extern void func_021C8860(u8 *p, int v);
extern void func_021C88C8(int p, u8 *q);
void *func_068995A4(u32 *p);
void func_068995B0(int a, int p, int x);
extern unsigned char data_0689D740[];

/*
 * note: C follower after the fixed linker veneer at 0x06899594.
 */
void *func_068995A4(u32 *p)
{
    *p = 1;
    return data_0689D740;
}


void func_068995B0(int a, int p, int x)
{
    u8 v;
    int n;
    int w;
    u8 *t;

    v = BTL_EVENT_GetVar(2);
    if (x == func_021B9A40(v) && func_021C8234(p, v) == 0) {
        switch (func_06898DE0(a, x)) {
        default:
        case 1:
            n = 8;
            break;
        case 2:
            n = 6;
            break;
        case 3:
            n = 4;
            break;
        }
        t = func_021C88A4(p, 7, 0x1f);
        w = func_021C7CF4(p, v);
        t[6] = v;
        ((struct Obj13633 *)t)->f4 = BTL_CALC_DivideMaxHpMin1(w, n);
        func_021C8838(t + 0xc, 2, 0x353);
        func_021C8860(t + 0xc, v);
        func_021C88C8(p, t);
    }
}
