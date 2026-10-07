/*
 * file:     unit_0219B508_p08.c
 * unit:     yes
 * function: func_0219BEB4, func_0219BED0, func_0219BF00, func_0219BF3C
 * address:  0x0219BEB4
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D046C  0x021D046C  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb
 */
#include "../../matched/include/Obj12076.h"
#include "../../matched/include/Obj19650.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0216D534(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021D046C(u32, u32, u32);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216DB24(int a0);
extern int func_0219BF48(u32 a);
void *func_0216D69C(void);
int func_0219BEB4(u32 a, u32 b);
int func_0219BED0(u32 a, u8 *s);
int func_0219BF00(u32 a, u32 b, u32 c, u32 d);
void func_0219BF3C(int a, u32 v);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219BEB4(u32 a, u32 b)
{
return func_021D046C(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)a))), a, b);
}


int func_0219BED0(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0219BF3C(a, func_0219BEB4(a, s[1]));
    }
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    s[0]++;
    return 0;
}


int func_0219BF00(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12076 *)((u8 *)(b)))->f2 == 0) {
    if (func_0219BF48(a) == 0) {
        if (func_0216DB24(a) == 1) {
            func_0219BF3C(a, func_0219BEB4(a, ((struct Obj12076 *)((u8 *)(b)))->f1));
        }
    }
    func_0216D568((void *)a, (2 << 14));
}
return 0;
}


void func_0219BF3C(int a, u32 v)
{
    ((struct Obj19650 *)((char *)func_0216D69C()))->f4 = v;
}
