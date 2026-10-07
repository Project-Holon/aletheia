/*
 * file:     weather_task_p30.c
 * unit:     yes
 * function: func_021A3460, func_021A3484, func_021A34EC, func_021A34F8
 * address:  0x021A3460
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
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A330C  0x021A330C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0219E784  0x0219E784  thumb
 *   func_021A3A10  0x021A3A10  thumb
 *   func_021A39E4  0x021A39E4  thumb
 */
#include "../../matched/include/Obj18021.h"
#include "../../matched/include/Obj19771.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u16 func_0216D5F8(void *p);
extern void *func_021A3074(u8 *p);
extern u32 func_021A330C(u32, u32, u32, u32, u32);
extern void *func_021A3960(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0207CCA4();
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021A3A10(u32 a);
extern int func_021A39E4(u8 *p);
int func_021A3460(u32 a, u32 b, u32 c, u32 d);
void func_021A3484(unsigned char **a, int b, s32 *c);
int func_021A34EC(u8 *p);
int func_021A34F8(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3460(u32 a, u32 b, u32 c, u32 d)
{
return func_021A330C(a, func_0216D5F8(func_021A3074((u8 *)a)), b, c, d);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A3484(unsigned char **a, int b, s32 *c)
{
    s16 v[4];
    s32 t1;
    s32 t2;
    s32 t3;
    void *h = func_021A3960(a[1]);

    if (func_02188CFC(a[0]) == 0) {
        s32 t;

        c[1] = 0;
        c[0] = func_021641E8(b);
        t = func_021641F8(b);
        c[0] = c[0] << 16;
        c[2] = t << 16;
        func_0207CCA4(c, c);
        return;
    }
    func_0219E784((u32)h, b, v);
    t3 = v[2];
    t2 = v[1];
    t1 = v[0];
    c[0] = t1;
    c[1] = t2;
    c[2] = t3;
}


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A34EC(u8 *p)
{
    return func_021A3A10(((struct Obj18021 *)p)->f4);
}


/*
 * Unlabelled leaf, tail-call thunk: the object's word at +0x4.
 * Sole blocker of the func_021645E0 MATCH (ov010).
 *
 * Addresses are Black-image addresses.
 */
int func_021A34F8(u8 *p)
{
    return func_021A39E4(*(u8 * *)&((struct Obj19771 *)p)->f4);
}
