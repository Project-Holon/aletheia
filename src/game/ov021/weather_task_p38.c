/*
 * file:     weather_task_p38.c
 * unit:     yes
 * function: func_021A3994, func_021A3998, func_021A39AC, func_021A39E4, func_021A3A10, func_021A3A20, func_021A3A3C
 * address:  0x021A3994
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
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3B3C  0x021A3B3C  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_021A31D0  0x021A31D0  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb
 *   func_02197C9C  0x02197C9C  thumb
 *   func_0219C648  0x0219C648  thumb
 *   func_020508EC  0x020508EC  arm
 */
#include "../../matched/include/Obj18045.h"
#include "../../matched/include/Obj19778.h"
#include "../../matched/include/Obj12729.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A3974(u8 *p);
extern u32 func_021A3B3C(u32, u32);
u32 func_021A398C(u8 *p);
void *func_021A3960(u8 *p);
u16 func_021A3190(int i, int j);
u16 func_0216D598(void *p);
void func_021A3AD8(u8 *p, int v);
int func_0216D7A8(void *p, unsigned int v);
extern int func_021A31D0(u16 id);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_02197C9C(u32 a);
extern int func_0219C648(u32 a);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
u32 func_021A3994(u8 *p);
int func_021A3998(u8 *a);
void func_021A39AC(u8 *p, int a);
int func_021A39E4(u8 *p);
int func_021A3A10(u32 a);
int func_021A3A20(u32 a);
int func_021A3A3C(u32 *p);


/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A3994(u8 *p)
{
    return ((struct Obj18045 *)p)->fC;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3998(u8 *a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021A3B3C((u32)a, func_021A3974(a));
}


void func_021A39AC(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A3190(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    ((struct Obj19778 *)p)->f2C = 0;
}


int func_021A39E4(u8 *p)
{
    if (func_0216D7A8(func_021A3960(p), 0) != 0xFFFF) {
        if (((struct Obj12729 *)p)->f2C == 1)
            return 1;
        (((struct Obj12729 *)p)->f2C)++;
    }
    return 0;
}


int func_021A3A10(u32 a)
{
return func_021A31D0(func_0216D598(func_021A3960((u8 *)a)));
}


int func_021A3A20(u32 a)
{
if (func_021A31D0(func_0216D598(func_021A3960((void *)a))) != 10) {
    return 1;
}
return 0;
}


/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --arm --region arm9:
 *   int func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 0x28;
 *       u16 v = *(u16 *)(e + 0x1C);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * Addresses are Black-image addresses.
 */
int func_021A3A3C(u32 *p)
{
    u16 v;
    u32 h;
    u32 k;

    h = func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)p[7])));
    if (func_02197C9C(p[7]) == 1 && func_0219C648(p[7]) == 1)
        return 1;
    k = func_0216D7A8((void *)p[7], 0);
    if (k != 0xFFFF && func_020508EC((u8 *)h, (u16)k, &v) != 0 && v == (0xFFFF >> 2))
        return 1;
    return 0;
}
