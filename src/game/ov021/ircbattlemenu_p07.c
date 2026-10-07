/*
 * file:     ircbattlemenu_p07.c
 * unit:     yes
 * function: func_02197F90, func_02197F9C, func_02197FA8, func_02197FB4, func_02197FC0
 * address:  0x02197F90
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
 *   func_02197F6C  0x02197F6C  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 */
#include "../../matched/include/Obj07465.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern int func_02197F6C(u32 a, u32 b);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_02163E7C(int a, int b);
extern void func_0216D60C(u8 *, u16);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D7CC(u8 *);
u32 func_02197F90(u32 a1);
u32 func_02197F9C(u32 a1);
u32 func_02197FA8(u32 a1);
u32 func_02197FB4(u32 a1);
void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e);


/*
 * Calls func_02197F6C(its own argument 1, 0x0) and returns 0x1.
 */
u32 func_02197F90(u32 a1)
{
    func_02197F6C(a1, 0x0);

    return 0x1;
}


/*
 * Calls func_02197F6C(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_02197F9C(u32 a1)
{
    func_02197F6C(a1, 0x1);

    return 0x1;
}


/*
 * Calls func_02197F6C(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_02197FA8(u32 a1)
{
    func_02197F6C(a1, 0x2);

    return 0x1;
}


/*
 * Calls func_02197F6C(its own argument 1, 0x3) and returns 0x1.
 */
u32 func_02197FB4(u32 a1)
{
    func_02197F6C(a1, 0x3);

    return 0x1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e)
{
    u16 *r;

    r = func_0216D6BC((int)a, (u32)12, c);
    r[0] = e;
    r[1] = d;
    ((struct Obj07465 *)r)->f4 = b;
    ((struct Obj07465 *)r)->f8 = c;
    func_02163E7C((int)a, (u16)b);
    func_0216D60C(a, b);
    func_0216D674(a, e);
    func_0216D568(a, 0x20);
    func_0216D7CC(a);
}
