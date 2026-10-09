/*
 * file:     fldmmdl_blact_p12.c
 * unit:     yes
 * function: func_0219DCC4, func_0219DD18, func_0219DD24, func_0219DD34, func_0219DD44, func_0219DD54, func_0219DD64, func_0219DD74, func_0219DD84, func_0219DD94, func_0219DDA4, func_0219DDB4, func_0219DDC4, func_0219DDD4, func_0219DDE4, func_0219DDF4, func_0219DE04, func_0219DE14, func_0219DE24, func_0219DE34, func_0219DE44, func_0219DE54, func_0219DE64, func_0219DE98, func_0219DECC, func_0219DEDC, func_0219DEEC, func_0219DEFC, func_0219DF0C, func_0219DF1C, func_0219DF2C, func_0219DF3C, func_0219DF4C, func_0219DF5C, func_0219DF6C, func_0219DF7C, func_0219DF8C, func_0219DF9C, func_0219DFAC, func_0219DFBC, func_0219DFCC, func_0219DFDC, func_0219DFEC, func_0219DFFC, func_0219E00C
 * address:  0x0219DCC4
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
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E354  0x0219E354  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_0219DC88  0x0219DC88  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj05013.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int BOOL;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
    u16 e;
    u16 f;
} S;

extern void *func_0219E348(void *a);
extern void func_0219E354(u32 a);
extern void func_021B8028();
extern u8 func_021B8040(u8 *p);
extern void func_0216D89C();
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *p);
extern void func_0219DC88(u32 a1, u32 a2, u32 a3, u32 a4);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_0216D5E0(int a0, int a1);
extern int func_02163F10(int a0);
extern void *func_0216D6D4(void *p);
extern void func_0219E370(u32 a, u32 b, u32 c);
extern void func_0219E6C8(u32, u16);
extern int func_0216D60C(int a0, int a1);
extern void func_020061E4(u32 a);
int func_0219DCC4(u32 o);
int func_0219DD18(u32 a, u32 b, u32 c, u32 d);
u32 func_0219DD24(u32 a1);
u32 func_0219DD34(u32 a1);
u32 func_0219DD44(u32 a1);
u32 func_0219DD54(u32 a1);
u32 func_0219DD64(u32 a1);
u32 func_0219DD74(u32 a1);
u32 func_0219DD84(u32 a1);
u32 func_0219DD94(u32 a1);
u32 func_0219DDA4(u32 a1);
u32 func_0219DDB4(u32 a1);
u32 func_0219DDC4(u32 a1);
u32 func_0219DDD4(u32 a1);
u32 func_0219DDE4(u32 a1);
u32 func_0219DDF4(u32 a1);
u32 func_0219DE04(u32 a1);
u32 func_0219DE14(u32 a1);
u32 func_0219DE24(u32 a1);
u32 func_0219DE34(u32 a1);
u32 func_0219DE44(u32 a1);
u32 func_0219DE54(u32 a1);
void func_0219DE64(u32 a, u32 b, u16 c, u16 d);
int func_0219DE98(u32 a);
u32 func_0219DECC(u32 a1);
u32 func_0219DEDC(u32 a1);
u32 func_0219DEEC(u32 a1);
u32 func_0219DEFC(u32 a1);
u32 func_0219DF0C(u32 a1);
u32 func_0219DF1C(u32 a1);
u32 func_0219DF2C(u32 a1);
u32 func_0219DF3C(u32 a1);
u32 func_0219DF4C(u32 a1);
u32 func_0219DF5C(u32 a1);
u32 func_0219DF6C(u32 a1);
u32 func_0219DF7C(u32 a1);
u32 func_0219DF8C(u32 a1);
u32 func_0219DF9C(u32 a1);
u32 func_0219DFAC(u32 a1);
u32 func_0219DFBC(u32 a1);
u32 func_0219DFCC(u32 a1);
u32 func_0219DFDC(u32 a1);
u32 func_0219DFEC(u32 a1);
u32 func_0219DFFC(u32 a1);
void func_0219E00C(u32 o, u32 id, u32 p, u8 q, S s, u32 fn);







/*
 * Addresses are Black-image addresses.
 */
int func_0219DCC4(u32 o)
{
    u32 a;
    u8 buf[12];

    a = (u32)func_0219E348((void *)o);
    func_0219E354(o);
    func_021B8028(a, buf);
    func_0216D89C(o, buf);
    if (func_021B8040((u8 *)a)) {
        return 0;
    }
    func_0216D568((void *)o, 0x440);
    func_0216D674((void *)o, 0);
    func_0216D7CC((u8 *)o);
    return 0;
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DD18(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 0);
return 0;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD24(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x10, 0x2);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD34(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x10, 0x2);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD44(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x10, 0x2);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD54(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x10, 0x2);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD64(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x8, 0x3);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD74(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x8, 0x3);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD84(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x8, 0x3);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD94(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x8, 0x3);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDA4(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x4, 0x4);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDB4(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x4, 0x4);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDC4(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x4, 0x4);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDD4(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x4, 0x4);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DDE4(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x2, 0x5);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DDF4(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x2, 0x5);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DE04(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x2, 0x5);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DE14(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x2, 0x5);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE24(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x4, 0xa);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE34(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x4, 0xa);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE44(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x4, 0xa);

    return 0x1;
}







/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE54(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x4, 0xa);

    return 0x1;
}







void func_0219DE64(u32 a, u32 b, u16 c, u16 d)
{
    u16 *q = func_0216D6BC((u32)a, (u32)4, c);
    q[0] = d;
    q[1] = c;
    func_0216D5E0((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_02163F10(a);
    func_0216D7CC((u8 *)a);
}







int func_0219DE98(u32 a)
{
    s16 *q = func_0216D6D4((void *)a);
    q[1]--;
    if (q[1] > 0)
        return 0;
    func_0216D568((void *)a, 0x400);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u8 *)a);
    return 1;
}







/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DECC(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x20, 0x1);

    return 0x1;
}







/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x20, 0x1);

    return 0x1;
}







/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEEC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x20, 0x1);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEFC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x20, 0x1);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF0C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x10, 0x2);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF1C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x10, 0x2);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF2C(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x10, 0x2);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF3C(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x10, 0x2);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF4C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x8, 0x3);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF5C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x8, 0x3);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF6C(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x8, 0x3);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF7C(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x8, 0x3);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DF8C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x2, 0x5);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DF9C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x2, 0x5);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DFAC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x2, 0x5);

    return 0x1;
}






/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DFBC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x2, 0x5);

    return 0x1;
}





/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFCC(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x4, 0x4);

    return 0x1;
}





/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x4, 0x4);

    return 0x1;
}





/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFEC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x4, 0x4);

    return 0x1;
}



/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFFC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x4, 0x4);

    return 0x1;
}


void func_0219E00C(u32 o, u32 id, u32 p, u8 q, S s, u32 fn)
{
    u8 *e;

    e = func_0216D6BC(o, 0x10, p);
    e[0xc] = id;
    ((struct Obj05013 *)e)->f0 = p;
    e[0xd] = q;
    e[0xe] = s.a;
    e[0xf] = s.c;
    ((struct Obj05013 *)e)->f8 = s.e;
    if (p == 0) {
        func_02163F10(o);
    } else {
        func_0219E370(o, (u16)id, 8);
        func_0219E6C8(o, id);
    }
    func_0216D568((void *)o, 0xa0);
    func_0216D60C((u32)o, (u16)id);
    func_0216D674((void *)o, s.a);
    func_0216D7CC((u8 *)o);
    if (fn) {
        func_020061E4(fn);
    }
}
