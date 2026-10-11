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
 *   func_021D57FC  0x021D57FC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   func_021D799C  0x021D799C  thumb
 *   func_021D7B74  0x021D7B74  thumb
 *   d_0689D728 0x0689D728 data a4
 */
#include "../../matched/include/Obj13632.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int a);
extern int func_021B9A40(int a);
extern int func_021C7CF4(int p, int a);
extern int func_021D57FC(void);
extern int func_021D799C(int a, int b);
extern u8 *func_021C88A4(int p, int n, int m);
extern int func_021D7B74(int a, int b);
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
    v = func_021D775C(2);
    if (x == func_021B9A40(v)) {
        w = func_021C7CF4(p, v);
        switch (func_021D799C(5, func_021D57FC())) {
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
        ((struct Obj13632 *)t)->f4 = func_021D7B74(w, n);
        func_021C8838(t + 0xc, 2, 0x356);
        func_021C8860(t + 0xc, v);
        func_021C88C8(p, t);
    }
}
