/*
 * file:     unit_06899260.c
 * unit:     yes
 * function: func_06899260, func_0689926C
 * address:  0x06899260
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
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_CALC_GetTypeAffinityVsPair  0x021D799C  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   d_0689D728 0x0689D728 data a4
 */
#include "../../matched/include/Obj13632.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int a);
extern int func_021B9A40(int a);
extern int func_021C7CF4(int p, int a);
extern int BTL_POKEPARAM_GetTypePair(void);
extern int BTL_CALC_GetTypeAffinityVsPair(int a, int b);
extern u8 *func_021C88A4(int p, int n, int m);
extern int BTL_CALC_DivideMaxHpMin1(int a, int b);
extern void func_021C8838(u8 *p, int n, int c);
extern void func_021C8860(u8 *p, int v);
extern void func_021C88C8(int p, u8 *q);
void *func_06899260(int *p);
void func_0689926C(int a0, int p, int x);
extern unsigned char d_0689D728[];


/*
 * Follower after the fixed linker veneer at 06899250; ends at 0689926C.
 */
void *func_06899260(int *p)
{
    *p = 1;
    return d_0689D728;
}


void func_0689926C(int a0, int p, int x)
{
    int n;
    u8 v;
    int w;
    u8 *t;

    n = 2;
    v = BTL_EVENT_GetVar(2);
    if (x == func_021B9A40(v)) {
        w = func_021C7CF4(p, v);
        switch (BTL_CALC_GetTypeAffinityVsPair(5, BTL_POKEPARAM_GetTypePair())) {
        default:
            n = 0x20;
            break;
        case 2:
            n = 0x10;
            break;
        case 3:
            n = 8;
            break;
        case 4:
            n = 4;
            break;
        case 5:
            break;
        }
        t = func_021C88A4(p, 7, 0x1f);
        t[6] = v;
        ((struct Obj13632 *)t)->f4 = BTL_CALC_DivideMaxHpMin1(w, n);
        func_021C8838(t + 0xc, 2, 0x356);
        func_021C8860(t + 0xc, v);
        func_021C88C8(p, t);
    }
}
