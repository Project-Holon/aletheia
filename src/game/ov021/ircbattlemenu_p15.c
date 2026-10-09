/*
 * file:     ircbattlemenu_p15.c
 * unit:     yes
 * function: func_02198C4C, func_02198CA4, func_02198CB4, func_02198CC4, func_02198CD4, func_02198CE4, func_02198CF4, func_02198D04, func_02198D14
 * address:  0x02198C4C
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
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_02198C08  0x02198C08  thumb
 */
#include "../../matched/include/Obj05005.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int BOOL;

extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern void *func_0216D568(void *p, u32 v);
extern int func_02163F10(int a0);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);
extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);
int func_02198C4C(u32 a, u32 *b);
u32 func_02198CA4(u32 a1);
u32 func_02198CB4(u32 a1);
u32 func_02198CC4(u32 a1);
u32 func_02198CD4(u32 a1);
u32 func_02198CE4(u32 a1);
u32 func_02198CF4(u32 a1);
u32 func_02198D04(u32 a1);
u32 func_02198D14(u32 a1);



/*
 * Addresses are Black-image addresses.
 */
int func_02198C4C(u32 a, u32 *b)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    func_02163FC0(a, ((struct Obj05005 *)p)->f0, b[p[3]]);
    func_02164010(a);
    p[3] = p[3] + 1;
    if (p[3] < p[2]) {
        return 0;
    }
    func_0216D568((void *)a, 1088);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}




/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CA4(u32 a1)
{
    func_02198C08(a1, 0x0, 0x6, 0x6);

    return 0x1;
}




/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CB4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x6, 0x6);

    return 0x1;
}




/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CC4(u32 a1)
{
    func_02198C08(a1, 0x2, 0x6, 0x6);

    return 0x1;
}



/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CD4(u32 a1)
{
    func_02198C08(a1, 0x3, 0x6, 0x6);

    return 0x1;
}



/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198CE4(u32 a1)
{
    func_02198C08(a1, 0x0, 0x6, 0xb);

    return 0x1;
}



/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198CF4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x6, 0xb);

    return 0x1;
}



/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198D04(u32 a1)
{
    func_02198C08(a1, 0x2, 0x6, 0xb);

    return 0x1;
}



/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x6, 0xb) and returns 0x1.
 */
u32 func_02198D14(u32 a1)
{
    func_02198C08(a1, 0x3, 0x6, 0xb);

    return 0x1;
}
