/*
 * file:     ircbattlemenu_p05.c
 * unit:     yes
 * function: func_02197F90, func_02197F9C, func_02197FA8, func_02197FB4, func_02197FC0, func_0219800C, func_02198060, func_02198074, func_02198088, func_0219809C, func_021980B0, func_021980C4, func_021980DC, func_021980F0, func_02198104, func_0219811C, func_02198134, func_02198148, func_0219815C, func_02198170, func_02198184, func_02198198, func_021981AC, func_021981C4, func_021981DC, func_021981F0, func_02198208, func_0219821C, func_02198234, func_02198248, func_02198260, func_02198278, func_02198290, func_021982A4, func_021982BC, func_021982D4, func_021982EC, func_02198300, func_02198318, func_0219834C, func_02198380, func_02198390, func_021983A0, func_021983B0, func_021983C0, func_021983D0, func_021983E0, func_021983F0, func_02198400, func_02198410, func_02198420, func_02198430, func_02198440, func_02198450, func_02198460, func_02198470, func_02198480, func_02198490, func_021984A0
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
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */
#include "../../matched/include/Obj07465.h"
#include "../../matched/include/Obj05990.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

typedef signed int     s32;

typedef signed char    s8;

extern int func_02197F6C(u32 a, u32 b);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_02163E7C(int a, int b);
extern void func_0216D60C(u8 *, u16);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D7CC(u8 *);
extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern int func_02163F10(int a0);
extern void func_0216D5E0(int a0, int a1);
u32 func_02197F90(u32 a1);
u32 func_02197F9C(u32 a1);
u32 func_02197FA8(u32 a1);
u32 func_02197FB4(u32 a1);
void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e);
u32 func_0219800C(u8 *p);
int func_02198060(u32 a);
int func_02198074(u32 a);
int func_02198088(u32 a);
int func_0219809C(u32 a);
int func_021980B0(u32 a);
int func_021980C4(u32 a);
int func_021980DC(u32 a, u32 b, u32 c, u32 d);
int func_021980F0(u32 a);
int func_02198104(u32 a);
int func_0219811C(u32 a);
int func_02198134(u32 a);
int func_02198148(u32 a, u32 b, u32 c, u32 d);
int func_0219815C(u32 a, u32 b, u32 c, u32 d);
int func_02198170(u32 a, u32 b, u32 c, u32 d);
int func_02198184(u32 a, u32 b, u32 c, u32 d);
int func_02198198(u32 a, u32 b, u32 c, u32 d);
int func_021981AC(u32 a);
int func_021981C4(u32 a);
int func_021981DC(u32 a);
int func_021981F0(u32 a);
int func_02198208(u32 a, u32 b, u32 c, u32 d);
int func_0219821C(u32 a);
int func_02198234(u32 a);
int func_02198248(u32 a);
int func_02198260(u32 a);
int func_02198278(u32 a);
int func_02198290(u32 a);
int func_021982A4(u32 a);
int func_021982BC(u32 a);
int func_021982D4(u32 a);
int func_021982EC(u32 a);
int func_02198300(u32 a);
void func_02198318(u32 a, u32 b, u16 c, u16 d);
int func_0219834C(u32 a);
u32 func_02198380(u32 a1);
u32 func_02198390(u32 a1);
u32 func_021983A0(u32 a1);
u32 func_021983B0(u32 a1);
u32 func_021983C0(u32 a1);
u32 func_021983D0(u32 a1);
u32 func_021983E0(u32 a1);
u32 func_021983F0(u32 a1);
u32 func_02198400(u32 a1);
u32 func_02198410(u32 a1);
u32 func_02198420(u32 a1);
u32 func_02198430(u32 a1);
u32 func_02198440(u32 a1);
u32 func_02198450(u32 a1);
u32 func_02198460(u32 a1);
u32 func_02198470(u32 a1);
u32 func_02198480(u32 a1);
u32 func_02198490(u32 a1);
u32 func_021984A0(u32 a1);





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





u32 func_0219800C(u8 *p)
{
    u8 *h;

    h = func_0216D6D4(p);
    func_02163FC0((int)p, (u16)(((struct Obj05990 *)h)->f4), (u32)(((struct Obj05990 *)h)->f8));
    func_02164010((int)p);
    ((struct Obj05990 *)h)->f2 = ((struct Obj05990 *)h)->f2 - 1;
    if (((struct Obj05990 *)h)->f2 > 0) {
        return 0;
    }
    func_0216D568(p, 0x440);
    func_02163F10((int)p);
    func_0216D674(p, 0);
    func_0216D7CC(p);
    return 0;
}





/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_02198060(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x800, 0x20, 0x1);
    return 1;
}





int func_02198074(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x800, 0x20, 0x1);
    return 1;
}





int func_02198088(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x800, 0x20, 0x1);
    return 1;
}





int func_0219809C(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x800, 0x20, 0x1);
    return 1;
}





int func_021980B0(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x1000, 0x10, 0x2);
    return 1;
}





int func_021980C4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x1000, 0x10, 0x2);
    return 1;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021980DC(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 2, (2 << 11), 16, 2);
return 1;
}





int func_021980F0(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x1000, 0x10, 0x2);
    return 1;
}





int func_02198104(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x2000, 0x8, 0x3);
    return 1;
}





int func_0219811C(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x2000, 0x8, 0x3);
    return 1;
}





int func_02198134(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x2000, 0x8, 0x3);
    return 1;
}





int func_02198148(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 3, (2 << 12), 8, 3);
return 1;
}





int func_0219815C(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 0, (4 << 12), 4, 4);
return 1;
}





int func_02198170(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 1, (1 << 14), 4, 4);
return 1;
}





int func_02198184(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 2, (2 << 13), 4, 4);
return 1;
}





int func_02198198(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 3, (4 << 12), 4, 4);
return 1;
}





int func_021981AC(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x8000, 0x2, 0x5);
    return 1;
}





int func_021981C4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x8000, 0x2, 0x5);
    return 1;
}





int func_021981DC(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x8000, 0x2, 0x5);
    return 1;
}





int func_021981F0(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x8000, 0x2, 0x5);
    return 1;
}





int func_02198208(u32 a, u32 b, u32 c, u32 d)
{
func_02197FC0((u8 *)a, 0, (1 << 16), 1, 0);
return 1;
}





int func_0219821C(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x10000, 0x1, 0x0);
    return 1;
}





int func_02198234(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x10000, 0x1, 0x0);
    return 1;
}





int func_02198248(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x10000, 0x1, 0x0);
    return 1;
}





int func_02198260(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x4000, 0x4, 0xa);
    return 1;
}





int func_02198278(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x4000, 0x4, 0xa);
    return 1;
}





int func_02198290(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x4000, 0x4, 0xa);
    return 1;
}





int func_021982A4(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x4000, 0x4, 0xa);
    return 1;
}





int func_021982BC(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x1000, 0x10, 0x5);
    return 1;
}





int func_021982D4(u32 a)
{
    func_02197FC0((u8 *)a, 0x1, 0x1000, 0x10, 0x5);
    return 1;
}





int func_021982EC(u32 a)
{
    func_02197FC0((u8 *)a, 0x2, 0x1000, 0x10, 0x5);
    return 1;
}





int func_02198300(u32 a)
{
    func_02197FC0((u8 *)a, 0x3, 0x1000, 0x10, 0x5);
    return 1;
}





void func_02198318(u32 a, u32 b, u16 c, u16 d)
{
    u16 *p;

    p = func_0216D6BC((u32)a, (u32)12, c);
    p[0] = d;
    p[1] = c;
    func_0216D5E0((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_02163F10(a);
    func_0216D7CC((u8 *)a);
}





int func_0219834C(u32 a)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    p[1]--;
    if (p[1] > 0) {
        return 0;
    }
    func_0216D568((void *)a, 0x400);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u8 *)a);
    return 0;
}





/*
 * Calls func_02198318(its own argument 1, 0x0, 0x20, 0x1) and returns 0x1.
 */
u32 func_02198380(u32 a1)
{
    func_02198318(a1, 0x0, 0x20, 0x1);

    return 0x1;
}





/*
 * Calls func_02198318(its own argument 1, 0x1, 0x20, 0x1) and returns 0x1.
 */
u32 func_02198390(u32 a1)
{
    func_02198318(a1, 0x1, 0x20, 0x1);

    return 0x1;
}





/*
 * Calls func_02198318(its own argument 1, 0x2, 0x20, 0x1) and returns 0x1.
 */
u32 func_021983A0(u32 a1)
{
    func_02198318(a1, 0x2, 0x20, 0x1);

    return 0x1;
}





/*
 * Calls func_02198318(its own argument 1, 0x3, 0x20, 0x1) and returns 0x1.
 */
u32 func_021983B0(u32 a1)
{
    func_02198318(a1, 0x3, 0x20, 0x1);

    return 0x1;
}





/*
 * Calls func_02198318(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983C0(u32 a1)
{
    func_02198318(a1, 0x0, 0x10, 0x2);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983D0(u32 a1)
{
    func_02198318(a1, 0x1, 0x10, 0x2);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983E0(u32 a1)
{
    func_02198318(a1, 0x2, 0x10, 0x2);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_021983F0(u32 a1)
{
    func_02198318(a1, 0x3, 0x10, 0x2);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198400(u32 a1)
{
    func_02198318(a1, 0x0, 0x8, 0x3);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198410(u32 a1)
{
    func_02198318(a1, 0x1, 0x8, 0x3);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198420(u32 a1)
{
    func_02198318(a1, 0x2, 0x8, 0x3);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_02198430(u32 a1)
{
    func_02198318(a1, 0x3, 0x8, 0x3);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198440(u32 a1)
{
    func_02198318(a1, 0x0, 0x4, 0x4);

    return 0x1;
}




/*
 * Calls func_02198318(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198450(u32 a1)
{
    func_02198318(a1, 0x1, 0x4, 0x4);

    return 0x1;
}



/*
 * Calls func_02198318(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198460(u32 a1)
{
    func_02198318(a1, 0x2, 0x4, 0x4);

    return 0x1;
}



/*
 * Calls func_02198318(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198470(u32 a1)
{
    func_02198318(a1, 0x3, 0x4, 0x4);

    return 0x1;
}



/*
 * Calls func_02198318(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198480(u32 a1)
{
    func_02198318(a1, 0x0, 0x2, 0x5);

    return 0x1;
}



/*
 * Calls func_02198318(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198490(u32 a1)
{
    func_02198318(a1, 0x1, 0x2, 0x5);

    return 0x1;
}



/*
 * Calls func_02198318(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_021984A0(u32 a1)
{
    func_02198318(a1, 0x2, 0x2, 0x5);

    return 0x1;
}
