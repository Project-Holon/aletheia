/*
 * file:     weather_task_p39.c
 * unit:     yes
 * function: func_021A3AA0, func_021A3AB8, func_021A3AC4, func_021A3AD0, func_021A3AD4, func_021A3AD8, func_021A3B3C
 * address:  0x021A3AA0
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3BB4  0x021A3BB4  thumb  ov021
 *   func_021A3C24  0x021A3C24  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219D208  0x0219D208  thumb  ov021
 *   func_0216CD88  0x0216CD88  thumb  ov010
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_021A3980  0x021A3980  thumb  ov021
 */
#include "../../matched/include/Obj18046.h"
#include "../../matched/include/Obj18047.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216D3CC(int a0);
extern void *func_021A3960(u8 *p);
extern u16 func_021A3BB4(u8 *p, u32 keys);
extern void func_021A3C24(u8 *p, int a);
void *func_0216D67C(void *a0);
u16 func_0216D598(void *p);
void func_0219D208(int a, unsigned int id);
int func_0216CD88(int a0);
u32 func_021A398C(u8 *p);
int func_021A31A4(int i, int v);
void func_0216E204(char *a, u32 v);
void func_021A3980(u8 *p, u32 a1);
int func_021A3AA0(u32 a);
u16 func_021A3AB8(u32 a, u32 v);
void func_021A3AC4(u32 a, u32 v);
void func_021A3AD0(u8 *p, u32 v);
u32 func_021A3AD4(u8 *p);
void func_021A3AD8(u8 *p, int a);
void func_021A3B3C(u8 *p, int a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3AA0(u32 a)
{
if (func_0216D3CC((int)func_021A3960((u8 *)a)) == 1) {
    return 1;
}
return 0;
}


/*
 * Widens the second argument to 16 bits before the tail call.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3AB8(u32 a, u32 v)
{
    return func_021A3BB4((u8 *)a, (u16)v);
}


void func_021A3AC4(u32 a, u32 v)
{
    func_021A3C24((u8 *)a, (u16)v);
}


/*
 * Field setter at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3AD0(u8 *p, u32 v)
{
    ((struct Obj18046 *)p)->f28 = v;
}


/*
 * Loads the 32-bit word at byte +0x28 of the object.
 */
u32 func_021A3AD4(u8 *p)
{
    return ((struct Obj18047 *)p)->f28;
}


void func_021A3AD8(u8 *p, int a)
{
    void *h = func_021A3960(p);
    u32 g = (u32)func_0216D67C(h);
    int r = func_0216D598(h);

    if (a == 1 || a == 4 || r == 1 || r == 4) {
        func_0219D208((int)h, a);
        func_0216CD88(g);
        return;
    }
    func_0216E204(h, func_021A31A4(func_021A398C(p), 0));
    func_0216CD88(g);
    func_0219D208((int)h, a);
    func_0216CD88(g);
}


void func_021A3B3C(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A31A4(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    func_021A3980(p, a);
}
