/*
 * file:     unit_02198D3C_p21.c
 * unit:     yes
 * function: func_0219AA08, func_0219AA38, func_0219AA68, func_0219AA78, func_0219AA88, func_0219AA98, func_0219AAA8, func_0219AAB8, func_0219AAC8, func_0219AAD8, func_0219AAE8, func_0219AAF8
 * address:  0x0219AA08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B404  0x0219B404  thumb  ov021
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219B374  0x0219B374  thumb  ov021
 */
#include "../../matched/include/Obj17956.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int BOOL;

extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p);
extern int func_0219B358(u32 a);
extern void func_0219B404(u32 a, u8 *s);
extern void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
extern void func_0219B374(u32 a, u8 *s);
int func_0219AA08(u32 a, u32 b, u32 c, u32 d);
void func_0219AA38(u32 a, u32 b, u32 c, u32 d);
void func_0219AA68(u32 a1);
void func_0219AA78(u32 a1);
void func_0219AA88(u32 a1);
void func_0219AA98(u32 a1);
void func_0219AAA8(u32 a1);
void func_0219AAB8(u32 a1);
void func_0219AAC8(u32 a1);
void func_0219AAD8(u32 a1);
void func_0219AAE8(u32 a1);
void func_0219AAF8(u32 a1);


int func_0219AA08(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 4));
    }
    ((struct Obj17956 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}


void func_0219AA38(u32 a, u32 b, u32 c, u32 d)
{
    u8 *p = func_0216D684(a, 12, c, d);
    p[2] = b;
    p[3] = c;
    p[4] = d;
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 8);
    }
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0xe) and returns nothing.
 */
void func_0219AA68(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0xe);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0xf) and returns nothing.
 */
void func_0219AA78(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0xf);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x10) and returns nothing.
 */
void func_0219AA88(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x10);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x11) and returns nothing.
 */
void func_0219AA98(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x11);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x12) and returns nothing.
 */
void func_0219AAA8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x12);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x13) and returns nothing.
 */
void func_0219AAB8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x13);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x14) and returns nothing.
 */
void func_0219AAC8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x14);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x15) and returns nothing.
 */
void func_0219AAD8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x15);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x16) and returns nothing.
 */
void func_0219AAE8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x16);
}


/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x17) and returns nothing.
 */
void func_0219AAF8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x17);
}
